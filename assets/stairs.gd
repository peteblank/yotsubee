extends CollisionShape2D

export(String) var nextScenePath

func _ready():
	pass


func _on_Stair_body_entered(body):
	print(body)
	Global.goto_scene(nextScenePath)
