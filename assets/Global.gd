extends Node

var current_scene = null

var entry_state = ""
var player_entry_direction = Vector2(0,0)

var currentSong = ""
var lastSongTime = 0

func _ready():
	var root = get_tree().get_root()
	current_scene = root.get_child(root.get_child_count() - 1)
	
	var music = GlobalScene.get_node("Music")
	if music.stream == null:
		if current_scene.song != "":
			music.stream = load(current_scene.song)
			music.play()
	if music.stream.resource_path != current_scene.song:
		music.stop()
		music.stream = null
		if current_scene.song != "":
			music.source = load(current_scene.song)
			music.play()

func goto_scene(path):
	call_deferred("_deferred_goto_scene", path)


func _deferred_goto_scene(path):
	current_scene.free()
	var s = ResourceLoader.load(path)
	current_scene = s.instance()
	get_tree().get_root().add_child(current_scene)
	get_tree().set_current_scene(current_scene)
	self._ready()
