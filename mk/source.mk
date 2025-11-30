

# NAME				=		cpp
NAME				=		ft_shmup


#############################################################################################
#																							#
#										// Directories										#
#																							#
#############################################################################################

# Directories
SRC_DIR				:=		./src/
HEADERS_DIR			:=		./inc/

# Sub Directories
UTILS_DIR			:=		utils/
SHIP_DIR			:=		ship/
BULLET_DIR			:=		bullet/

# for a new DIR add a new :
# NEW_DIR			:=		new/


#############################################################################################
#																							#
#										// SOURCE											#
#																							#
#############################################################################################


HEADERS_D			:=		./incs/


HEADERS				:=		Debug.hpp



SRC					:=		main.cpp		\
							AGameEntity.cpp


SRC_UTILS			:=		Board.cpp		\
							Debug.cpp		\
							Clock.cpp		\
							HpBar.cpp

SRC_SHIP			:=		AShip.cpp		\
							ShipAlly.cpp	\
							ShipEnnemie.cpp

SRC_BULLET			:=		ABullet.cpp		\
							BulletAlly.cpp	\
							BulletEnnemie.cpp


# for a new SRC add a new :
# SRC_NEW				:=


# Every now src_dir add a addprifix like that :
#	$(addprefix $(NEW_DIR), $(SRC_NEW))


SRCS				=		$(addprefix $(SHIP_DIR), $(SRC_SHIP)) 		\
							$(addprefix $(BULLET_DIR), $(SRC_BULLET))	\
							$(addprefix $(UTILS_DIR), $(SRC_UTILS))		\
							$(SRC)
							
