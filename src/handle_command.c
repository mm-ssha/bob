#include <stdio.h>
#include <stdlib.h>

#include "bob.h"

int handle_command(int command_id, int argc, char **argv)
{
	if (command_id == 0){
		printf("Invalid command.\n");
		return 1;
	}
	if (command_id == 1){
		system("mkdir .bob");
		system("touch .bob/compiler_flags");
		system("touch .bob/last_edits");	
		system("touch .bob/temp_time");
		system("mkdir .bob/object_files");
	}
	if (command_id == 2){
		FILE *comp = fopen(".bob/compiler_flags", "w");
		if (!comp) fprintf(stderr, ".bob/compiler_flags failed to open in handle_command()\n");

		fputs("gcc ", comp);
		for (int i = 2; i < argc; i++){
			fputs(argv[i], comp);
			fputc(' ', comp);
		}
		char out[25] = {"-o .bob/bob_executable "};
		fputs(out, comp);

		fclose(comp);
	}
	if (command_id == 3){
		system("ls -R -l --time-style=+%Y%m%d%H%M%S > .bob/temp_time");
		format_compare();
		compile_objects();
	}
	if (command_id == 4){
		char cmd[MAX_RUN_COMMAND_LENGTH] = {"./.bob/bob_executable "};

		int cmd_pos = 22;
		for (int i = 2; i < argc; i++){
			int pos = 0;
			while (argv[i][pos] != '\0'){
				cmd[cmd_pos++] = argv[i][pos++];
			}
			cmd[cmd_pos++] = ' ';
		}

		system(cmd);
	}
	return 0;
}
