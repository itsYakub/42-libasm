AS		:= nasm
ASFLAGS	:= -felf64 -g
SRCS	:= ./ft_read.s ./ft_strcmp.s ./ft_strcpy.s ./ft_strdup.s ./ft_strlen.s ./ft_write.s
OBJS	:= $(SRCS:.s=.o)
NAME	:= ./libasm.a

# ========

$(NAME) : $(OBJS)
	ar rcs $@ $^

$(OBJS) : %.o : %.s
	$(AS) $(ASFLAGS) $< -o $@

# ========

.PHONY : all

all : $(NAME)

.PHONY : re

re : fclean re

.PHONY : clean

clean :
	rm -f $(OBJS)

.PHONY : fclean

fclean: clean
	rm -f $(NAME)
