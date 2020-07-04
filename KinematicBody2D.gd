extends KinematicBody2D

const MAX_SPEED= 100
var velocity = Vector2.ZERO

onready var animationplayer = $AnimationPlayer
onready var animationtree = $AnimationTree
onready var animationstate = $AnimationTree.get("parameters/playback")

func _ready():
	if Global.entry_state != "":
		var root = get_tree().get_root()
		var spawn_position = root.get_node("Node2D/Spawns").get_node(Global.entry_state)
		self.position = spawn_position.position
		animationtree.set("parameters/idle/blend_position", Global.player_entry_direction)

func _physics_process(delta):
	var input_vector = Vector2.ZERO
	input_vector.x = Input.get_action_strength("ui_right") - Input.get_action_strength("ui_left")
	input_vector.y = Input.get_action_strength("ui_down") - Input.get_action_strength("ui_up")
	input_vector = input_vector.normalized()
	
	if input_vector != Vector2.ZERO:
		velocity=input_vector
		animationtree.set("parameters/idle/blend_position", input_vector)
		animationtree.set("parameters/walk/blend_position", input_vector)
		animationstate.travel("walk")
	else:
		velocity =Vector2.ZERO
		animationstate.travel("idle")
		
	velocity = move_and_slide(velocity * MAX_SPEED)
	
