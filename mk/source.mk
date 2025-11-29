

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

# for a new DIR add a new :
# NEW_DIR			:=		new/


#############################################################################################
#																							#
#										// SOURCE											#
#																							#
#############################################################################################


HEADERS_D			:=		./incs/


HEADERS				:=		Debug.hpp



SRC					:=		main.cpp


SRC_UTILS			:=		Debug.cpp


# for a new SRC add a new :
# SRC_NEW				:=


# Every now src_dir add a addprifix like that :
#	$(addprefix $(NEW_DIR), $(SRC_NEW))


SRCS				=		$(addprefix $(UTILS_DIR), $(SRC_UTILS))\
							$(SRC)
							
