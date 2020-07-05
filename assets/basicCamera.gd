extends Camera2D

var target

func _ready():
	self.target = get_tree().get_root().get_node("Node2D/YSort/player")


func _process(_delta):
	var newPos = target.position
	#newPos.x = round(newPos.x)
	#newPos.y = round(newPos.y)
	self.position = newPos
