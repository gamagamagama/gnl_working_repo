
#include "get_next_line_bonus.h"


char	*ft_next(char *string_buffer)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	while (string_buffer[i] && string_buffer[i] != '\n')
		i++;
	if(!string_buffer[i])
	{
		free(string_buffer);
		return (NULL);
	}
	next = ft_calloc((ft_strlen(string_buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (string_buffer[i])
	{
		next[j++] = string_buffer[i++];
	}
	next[j] = '\0';
	free(string_buffer);
	return (next);
}

char	*ft_line(char *string_buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!string_buffer[i])
		return (NULL);
	while (string_buffer[i] && string_buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (line == 0)
		return (NULL);
	i = 0;
	while (string_buffer[i] && string_buffer[i] != '\n')
	{
		line[i] = string_buffer[i];
		i++;
	}
	if (string_buffer[i] == '\n')
	{
		line[i] = string_buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
	
}


char	*ft_free(char *result_buffer, char *string_buffer)
{
	char *temp_buffer;

	temp_buffer = ft_strjoin(result_buffer, string_buffer);
	free(result_buffer);
	return(temp_buffer);
}

char	*ft_reader(int fd, char *result)
{
	char *string_buffer;
	int	byte;

	string_buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, string_buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(string_buffer);
			return(NULL);
		}
		string_buffer[byte] = 0;
		result = ft_free(result, string_buffer);
		if (ft_strrchr(string_buffer, '\n'))
		{
			break;
		}
		
	}
	free(string_buffer);
	return(result);

}

char	*get_next_line(int fd)
{
	static char *string_buffer[FOPEN_MAX];
	char		*line;

	if(fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return(NULL);
	string_buffer[fd] = ft_reader(fd, string_buffer[fd]);
	if(!string_buffer[fd])
		return(NULL);
	line = ft_line(string_buffer[fd]);
	string_buffer[fd] = ft_next(string_buffer[fd]);
	return(line);

}



// int main(void)
// {
// 	#define BUFFER_SIZE 5

//     int fd;
//     char *line;

//     fd = open("example.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return 1;
//     }
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("Line: %s", line);
//         free(line); 
//     }
//     close(fd);

//     return 0;
// }