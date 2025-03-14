#include "get_next_line.h"

char    *get_next_line(int fd)
{
    int i = 0;
    int rd = 0;
    char character;
    char *buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));

    while(i < BUFFER_SIZE && (rd = read(fd, &character, 1)) > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break;
    }
    if (i == 0 && rd <= 0)
    {
        free(buffer);
        return (NULL);
    }
    buffer[i] = '\0';
    return(buffer);
}

int main()
{
    int fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Error opeining the file\n");
        exit(1);
    }
    while((line = get_next_line(fd)))
    {
        printf("line: %s\n", line);
        free(line);
    }
    close(fd);
    return(0);
}
