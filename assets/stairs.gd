extends CollisionShape2D

export(String) var nextScenePath
export(String) var targetLocation = ""
export(bool) var inverseDirection = false

func _ready():
	pass


func _on_Stair_body_entered(body):
	if body.name == "player":
		var root = get_tree().get_root()
		
		#Store music information
		
		#Store spawn information
		Global.entry_state = targetLocation
		var animTree = root.get_node("Node2D/YSort/player").get_node("AnimationTree")
		var dir = animTree.get("parameters/idle/blend_position")
		dir = -1*dir if inverseDirection else dir
		Global.player_entry_direction = dir
		
		#Switch scenes
		Global.goto_scene(nextScenePath)
