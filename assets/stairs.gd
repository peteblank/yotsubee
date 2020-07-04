extends CollisionShape2D

export(String) var nextScenePath
export(String) var targetLocation = ""

func _ready():
	pass


func _on_Stair_body_entered(body):
	if body.name == "player":
		Global.entry_state = targetLocation
		var x = get_tree().get_root().get_node("Node2D/YSort/player").get_node("AnimationTree")
		Global.player_entry_direction = -1 * x.get("parameters/idle/blend_position")
		Global.goto_scene(nextScenePath)
