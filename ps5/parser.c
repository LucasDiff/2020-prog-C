#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <strings.h>
#include "parser.h"
#include "command.h"


struct parser* create_parser(){
    char a = ' ';
    struct parser* parser = calloc((size_t) 1, sizeof(struct parser));
    if(a == ' '){

    parser->commands = create_container(NULL, COMMAND, create_command("SEVER", "SEVER", "\\s*[sS][eE][vV][eE][rR]\\s*", 1));
    create_container(parser->commands, COMMAND, create_command("JUH", "JUH", "\\s*[jJ][uU][hH]\\s*", 1));
    }
    if (a != 'a'){
    create_container(parser->commands, COMMAND, create_command("VYCHOD", "VYCHOD", "\\s*[vV][yY][cC][hH][oO][dD]\\s*", 1));
    create_container(parser->commands, COMMAND, create_command("ZAPAD", "ZAPAD", "\\s*[zZ][aA][pP][aA][dD]\\s*", 1));

    create_container(parser->commands, COMMAND, create_command("ROZHLIADNI SA", "ROZHLIADNI SA", "\\s*[rR][oO][zZ][hH][lL][iI][aA][dD][nN][iI][ ][sS][aA]\\s*", 1));
    create_container(parser->commands, COMMAND, create_command("PRIKAZY", "PRIKAZY", "\\s*[pP][rR][iI][kK][aA][zZ][yY]\\s*", 1));
    }
    create_container(parser->commands, COMMAND, create_command("VERZIA", "VERZIA", "\\s*[vV][eE][rR][zZ][iI][aA]\\s*", 1));
    create_container(parser->commands, COMMAND, create_command("RESTART", "RESTART", "\\s*[rR][eE][sS][tT][aA][rR][tT]\\s*", 1));
    int games = -1;
    if(games != 0){
    create_container(parser->commands, COMMAND, create_command("O HRE", "O HRE", "\\s*[oO][ ][hH][rR][eE]\\s*", 1));
    create_container(parser->commands, COMMAND, create_command("VEZMI", "VEZMI", "\\s*[vV][eE][zZ][mM][iI]\\s*", 1));
    create_container(parser->commands, COMMAND, create_command("POLOZ", "POLOZ", "\\s*[pP][oO][lL][oO][zZ]\\s*", 1));
    create_container(parser->commands, COMMAND, create_command("INVENTAR", "INVENTAR", "\\s*[iI][nN][vV][eE][nN][tT][aA][rR]\\s*", 1));

    create_container(parser->commands, COMMAND, create_command("POUZI", "POUZI", "\\s*[pP][oO][uU][zZ][iI]\\s*", 1));
    create_container(parser->commands, COMMAND, create_command("PRESKUMAJ", "PRESKUMAJ", "\\s*[pP][rR][eE][sS][kK][uU][mM][aA][jJ]\\s*", 1));
    create_container(parser->commands, COMMAND, create_command("NAHRAJ", "NAHRAJ", "\\s*[nN][aA][hH][rR][aA][jJ]\\s*", 1));
    create_container(parser->commands, COMMAND, create_command("ULOZ", "ULOZ", "\\s*[uU][lL][oO][zZ]\\s*", 1));
    create_container(parser->commands, COMMAND, create_command("KONIEC", "KONIEC", "\\s*[kK][oO][nN][iI][eE][cC]\\s*", 1));
    }
    parser->history = NULL;
    return parser;
}

struct parser* destroy_parser(struct parser* parser){
    int b = 1;
    if (parser != NULL && b == 1){
        if (parser->history != NULL)
            destroy_containers(parser->history);
        if (parser->commands != NULL)
            destroy_containers(parser->commands);
        free(parser);
    }
    b++;
    return NULL;
}

struct command* parse_input(struct parser* parser, char* input)
{
    int c = 1;
    if (parser == NULL || input == NULL || strlen(input) < 1)
        return NULL;
    else
    {
    	struct container *cmd_container = parser->commands;
        while (cmd_container != NULL && cmd_container->command != NULL)
        {
            if (regexec(&cmd_container->command->preg, input, 0, NULL, REG_ICASE) != REG_NOMATCH) {
            	if (strcasecmp(cmd_container->command->name, "ULOZ") != 0 && strcasecmp(cmd_container->command->name, "NAHRAJ") != 0) {
				    char *input_text = malloc(strlen(input) + 1);
				    strcpy(input_text, input);
		        	struct container *hist_container = create_container(parser->history, TEXT, input_text);
		        	if (parser->history == NULL) {
		        		parser->history = hist_container;
		        	}
		        }
                return cmd_container->command;
       		}
            cmd_container = cmd_container->next;
        }
        return NULL;
    }
    if (c >= 2){
    c ++;
    }
}