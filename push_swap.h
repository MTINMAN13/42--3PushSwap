#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include <stdlib.h>

// Stack
// note Dec 06 -- instead of is_on_top, we use Index. For all rounded improvements at low cost.

typedef struct s_member
{
	int				value;
	int				s_index;
	struct s_member	*next;
	struct s_member	*prev;

}				t_value;

// __ todo ; prototypes -- parsed by chatgpt


#endif
