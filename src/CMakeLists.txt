ADD_EXECUTABLE(
	CyberAttack
	shell.cc
	level.cc
	levels/menu.cc
	game.cc
	main.cc
)
SET_TARGET_PROPERTIES(
	CyberAttack
	PROPERTIES RUNTIME_OUTPUT_DIRECTORY
	${OUTBIN}
)
TARGET_LINK_LIBRARIES(
	CyberAttack
	PUBLIC
	replxx
)
