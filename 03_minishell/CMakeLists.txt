cmake_minimum_required(VERSION 3.23)
project(minishell C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-I/opt/homebrew/opt/readline/include -L/opt/homebrew/opt/readline/lib -lreadline")

include_directories(src)
include_directories(includes)
include_directories(src/parse)
include_directories(src/execute)
include_directories(src/util)

add_executable(03_minishell
        src/main.c
        includes/libft.h
        includes/minishell.h
        includes/parse.h
        includes/execute.h
        libft/ft_atoi.c
#        libft/ft_bzero.c
#        libft/ft_calloc.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isprint.c
        libft/ft_itoa.c
#        libft/ft_lstadd_back.c
#        libft/ft_lstadd_front.c
#        libft/ft_lstclear.c
#        libft/ft_lstdelone.c
#        libft/ft_lstiter.c
#        libft/ft_lstlast.c
#        libft/ft_lstmap.c
#        libft/ft_lstnew.c
#        libft/ft_lstsize.c
#        libft/ft_memchr.c
#        libft/ft_memcmp.c
#        libft/ft_memcpy.c
#        libft/ft_memmove.c
#        libft/ft_memset.c
        libft/ft_putchar_fd.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr_fd.c
        libft/ft_split.c
        libft/ft_strchr.c
        libft/ft_strdup.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strlcpy.c
        libft/ft_strlen.c
        libft/ft_strmapi.c
        libft/ft_strncmp.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strtrim.c
        libft/ft_substr.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/libft.h
        src/execute/builtin.c
        src/execute/execute.c
        src/execute/ft_cd.c
        src/execute/ft_echo.c
        src/execute/ft_env.c
        src/execute/ft_exe.c
        src/execute/ft_exit.c
        src/execute/ft_export.c
        src/execute/ft_fork.c
        src/execute/ft_here_doc.c
        src/execute/ft_pwd.c
        src/execute/ft_rdir.c
        src/execute/ft_unset.c
        src/execute/here_util.c
        src/parse/chunks.c
        src/parse/cmds.c
        src/parse/free.c
        src/parse/node.c
        src/parse/parse.c
        src/parse/replace.c
        src/parse/signal.c
        src/parse/tokens.c
        src/parse/utils2.c
        src/parse/utils.c
        src/parse/utils3.c
        src/util/env.c
        src/util/find_env.c
        src/util/find_env_add.c
        src/util/ft_error_exit.c
        src/util/ft_strjoin2.c
        src/util/ft_strcmp.c
        )