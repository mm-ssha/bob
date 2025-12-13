#ifndef BOBTHEBUILDER_SRC_BOB_H
#define BOBTHEBUILDER_SRC_BOB_H

int equal_strings    (char *s1, char *s2);
int determine_command(char *arg);
int handle_command   (int command_id, int argc, char **argv);
int format_compare   ();
int compile_objects  ();

#ifndef MAX_LINE_LENGTH
	#define MAX_LINE_LENGTH 250
#endif
#ifndef MAX_COMPILE_TO_OBJECTS_LENGTH
	#define MAX_COMPILE_TO_OBJECTS_LENGTH 25000
#endif
#ifndef MAX_COMPILE_TO_EXECUTABLE_LENGTH
	#define MAX_COMPILE_EXECUTABLE_LENGTH 30000
#endif
#ifndef MAX_FILES
	#define MAX_FILES 500
#endif
#ifndef MAX_RUN_COMMAND_LENGTH
	#define MAX_RUN_COMMAND_LENGTH 150
#endif

#endif
