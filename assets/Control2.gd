extends Control

var dialog = ["good morning yotsubee", "heeey","Could you do me a favor?",
"We're out of milk and eggs, could you go to the store and buy some?","...","Here's 100 yans, keep the change"]
# Declare member variables here. Examples:
# var a = 2
# var b = "text"
var dialog_index=0
var finished = false


func _ready():
	load_dialog()

func _process(delta):
	#$"next-indicator".visible = finished
	if Input.is_action_just_pressed("ui_accept"):
		load_dialog()

func load_dialog():
	if dialog_index < dialog.size():
		finished = false
		$RichTextLabel.bbcode_text = dialog[dialog_index]
		$RichTextLabel.percent_visible = 0
		$Tween.interpolate_property(
			$RichTextLabel, "percent_visible", 0, 1, 1,
			Tween.TRANS_LINEAR, Tween.EASE_IN_OUT
		)
		$Tween.start()
	else:
		queue_free()
	dialog_index += 1


func _on_Tween_tween_completed(object, key):
	finished = true


# Called every frame. 'delta' is the elapsed time since the previous frame.


