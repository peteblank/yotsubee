extends Area2D


# Called when the node enters the scene tree for the first time.
func _ready():
	# warning-ignore:return_value_discarded
	pass # Replace with function body.

func _physics_process(delta):
		var bodies=get_overlapping_bodies()
		for body in bodies:
			if body.name == "player":
				get_tree().change_scene("res://assets/room3.tscn") 
		pass
		# Replace with function body.






