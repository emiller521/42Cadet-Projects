/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 10:20:15 by elmiller          #+#    #+#             */
/*   Updated: 2019/06/21 10:31:29 by elmiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>
#define NULL __DARWIN_NULL

typedef char bool;
#define TRUE 1
#define FALSE 0

char* bool_to_str(bool value)
{
	if (value == TRUE)
		return("TRUE");
	else
		return("FALSE");
}

typedef struct s_option
{
	int		option_l;
	int		option_t;
	int		option_r;
	int		option_a;
	char	**directories;
  char  *soft_name;
}              t_option;

void option_init(t_option* opt)
{
	opt->option_l = FALSE;
	opt->option_a = FALSE;
	opt->option_t = FALSE;
	opt->option_r = FALSE;
  opt->directories = NULL;
}

void option_parse(t_option* opt, int ac, char** av)
{
  int i;
  int j;

  i = 1;
  while(ac < i)
  {
    j = 1;
    while(av[i][0] == '-' && av[i][j])
    {
      if(av[i][j] == 'a')
        opt->option_a = TRUE;
      if(av[i][j] == 't')
        opt->option_t = TRUE;
      if(av[i][j] == 'l')
        opt->option_l = TRUE;
      if(av[i][j] == 'r')
        opt->option_r = TRUE;
      j++;
    }
    i++;
  }
}

void option_get(t_option* opt, int ac, char** av)
{
  option_init(opt);
  option_parse(opt, ac, av);
}

void option_print(t_option* opt)
{
  printf("Binary: %s\n", opt->soft_name);
  printf("Option loaded: \n");
  printf("l -> %s\n", bool_to_str(opt->option_l));
  printf("a -> %s\n", bool_to_str(opt->option_a));
  printf("r -> %s\n", bool_to_str(opt->option_r));
  printf("t -> %s\n", bool_to_str(opt->option_t));
  printf("Directories: \n");
  for (int index = 0; opt->directories && opt->directories[index]; index++) {
    printf("%s\n", opt->directories[index]);
  }
}

typedef struct s_elem
{
  char *data_1;
  char *data_2;
  char *stat;
  struct s_elem *next;

}         t_elem;

struct stat* stat_file(char* dir, char* filename)
{

}
struct stat* elem_get_stat(t_elem* a)
{
  if (a->stat == NULL) {
    a->stat = stat_file(a->data_1, a->data_2);
  }
  return (a->stat);
}

int elem_get_file_mode(t_elem* elem)
{

}

int elem_get_blocks_allocated(t_elem* elem)
{

}

int elem_get_number_links(t_elem* elem)
{

}
char* elem_get_owner_name(t_elem* elem) {
}
char* elem_get_group_name(t_elem* elem) {
}
off_t elem_get_number_bytes(t_elem* elem) {
}
struct timespec* elem_get_last_modified_date(t_elem* elem) {
}
char* elem_get_pathname(t_elem* elem) {
}
typedef struct s_list
{
  char*       directory;
  t_elem*     begin;
  t_elem*     end;
}              t_list;

void list_init(t_list* list, char* directory)
{

}
void list_push_back_elem(t_list* list, t_elem* new)
{

}

void list_push_back(t_list* list, char* data)
{
  t_elem *node = list->begin;
  t_elem *new_elem;

  while(node->next != NULL)
  {
    node = node->next;
  }
  node->next = (data);



}

void list_load(t_option* opt, t_list* list, DIR* dirp)
{
  struct dirent*  dp;

  dirp = opendir(".");
  if (dirp == NULL);
    printf("Error: Empty");
  while ((dp = readdir(dirp)) != NULL)
  {
    list_push_back(list, dp->d_name);
    printf("%s\n", dp->d_name);
  }
}
void* ls_sorting_algorithm(t_option* opt) {
}
size_t uintlen(int nbr) {
}
enum {
  ST_MODE = 0,
  NLINK = 1,
  UID   = 2,
  GID   = 3,
  SIZE  = 4,
 
 -+ DATE  = 5,
  NAME  = 6,
  NBR_COLUMNS = 7
};
#define DATE_MAX_SIZE 30
char get_file_type(int mode) {
}
void print_mode(mode_t st_mode) {
}
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
int alignment_size_init(t_list* list, size_t* alignment_size) {
  t_elem* it = list->begin;
  int blocks = 0;
  while (it != NULL) {
    blocks += elem_get_blocks_allocated(it);
    alignment_size[NLINK] = MAX(alignment_size[NLINK], uintlen(elem_get_number_links(it)));
    alignment_size[UID]   = MAX(alignment_size[UID],   strlen(elem_get_owner_name(it)));
    alignment_size[GID]   = MAX(alignment_size[GID],   strlen(elem_get_group_name(it)));
    alignment_size[SIZE]  = MAX(alignment_size[SIZE],  uintlen(elem_get_number_bytes(it)));
    alignment_size[DATE]  = MAX(alignment_size[DATE],  strlen(format_date(elem_get_last_modified_date(it)->tv_sec)));
    alignment_size[NAME]  = MAX(alignment_size[NAME],  strlen(elem_get_pathname(it)));
    it = it->next;
  }
  return (blocks);
}
void list_detailed_print_display(t_list* list, int* alignment_size, int blocks) {
  t_elem* it = list->begin;
  printf("total %d\n", blocks);
  while (it != NULL) {
    print_mode(elem_get_file_mode(it));
    printf("  ");
    printf("%*u ",   alignment_size[NLINK], elem_get_number_links(it));
    printf("%*s  ",  alignment_size[UID],   elem_get_owner_name(it));
    printf("%*s  ",  alignment_size[GID],   elem_get_group_name(it));
    printf("%*lld ", alignment_size[SIZE],  elem_get_number_bytes(it));
    printf("%*s ",   alignment_size[DATE],  format_date(elem_get_last_modified_date(it)->tv_sec));
    printf("%s\n",   elem_get_pathname(it));
    it = it->next;
  }
}
void list_detailed_print(t_list* list) {
  size_t  alignment_size[NBR_COLUMNS];
  int     blocks;
  memset(&alignment_size[0], 0, sizeof(alignment_size[0]) * NBR_COLUMNS);
  blocks = alignment_size_init(list, &alignment_size[0]);
  list_detailed_print_display(list, (int *)(&alignment_size[0]), blocks);
}
void listing(t_option* opt, char *directory) {
}
void do_ls(t_option* opt) {
  if (opt->directories) {
  }
  else {
  }
}


int main(int ac, char **av) {
  t_option opt;
  option_get(&opt, ac, av);
   option_print(&opt);
  //do_ls(&opt);
  return (EXIT_SUCCESS);
}