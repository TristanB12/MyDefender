##
## EPITECH PROJECT, 2019
## Make file
## File description:
## make file
##

SRC	=	src/menu/main.c \
		src/menu/menu.c \
		src/menu/levels.c \
		src/menu/music.c \
		src/level/level_checkpoint.c \
		src/level/level_mobs.c \
		src/level/level_waves.c \
		src/level/level.c \
		src/mobs/mobs.c \
		src/mobs/mobs_life.c \
		src/mobs/mobs_set_position.c \
		src/game.c \
		src/level/level_tower_emplacement.c \
		src/interface/interface_initialisation.c \
		src/interface/interface.c \
		src/towers/tower.c \
		src/towers/can_be_droped.c \
		src/towers/destroy_last_tower.c \
		src/towers/tower_init.c \
		src/menu/change_window.c \
		src/menu/quit.c \
		src/towers/tower_actions.c \
		src/spells/spells_init.c \
		src/spells/spells.c \
		src/towers/tower_shot.c \
		src/menu/pause.c \
		src/spells/spells_effects.c \
		src/spells/spells_rects.c \
		src/win_loss_conditions.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	my_defender

CFLAGS  =	-I./include

CSFLAGS	=	-l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio -lm

LDFLAGS = -L./lib/my -lmy

all:	$(NAME)

$(NAME): libmy $(OBJ)
	gcc -o $(NAME) -v -g $(OBJ) $(CSFLAGS) -I./include $(LDFLAGS)

libmy:
		make -C ./lib/my all

clean:
		rm -rf $(OBJ)
		make -C ./lib/my/ clean

fclean:		clean
		rm -rf $(NAME)
		make -C ./lib/my/ fclean

re:		fclean all
