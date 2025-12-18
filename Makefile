# ========

MK_ROOT		= $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
MK_NAME		= $(MK_ROOT)libasm

# ========

AS		= nasm
AR		= ar
CC		= cc
ASFLAGS	= -felf64 -g
ARFLAGS = rcs
CFLAGS  = -Wall -Wextra -Werror -ggdb3

# ========

OBJS	= $(SRCS:.s=.o)
SRCS	= $(MK_ROOT)ft_read.s 	\
		  $(MK_ROOT)ft_strcmp.s \
		  $(MK_ROOT)ft_strcpy.s \
		  $(MK_ROOT)ft_strdup.s \
		  $(MK_ROOT)ft_strlen.s \
		  $(MK_ROOT)ft_write.s

# ========

NAME	= $(MK_NAME).a

# ========

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^


$(OBJS) : %.o : %.s
	$(AS) $(ASFLAGS) $< -o $@

# ========

.PHONY : all

all : $(NAME)


.PHONY : re

re : fclean all


.PHONY : clean

clean :
	rm -f $(OBJS)


.PHONY : fclean

fclean : clean
	rm -f $(NAME)

# ========

.PHONY : example

example : $(NAME)
	$(CC) $(CFLAGS) $(MK_ROOT)example.c $^

# ========
