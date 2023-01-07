/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_JSON_INTERNAL_H
# define FT_JSON_INTERNAL_H

# include "ft_json.h"

# include "ft_stringbuilder.h"

typedef enum e_ft_json_value_type
{
	FT_JSON_VALUE_TYPE_ERROR,
	FT_JSON_VALUE_TYPE_NULL,
	FT_JSON_VALUE_TYPE_BOOLEAN,
	FT_JSON_VALUE_TYPE_NUMBER,
	FT_JSON_VALUE_TYPE_STRING,
	FT_JSON_VALUE_TYPE_LIST,
	FT_JSON_VALUE_TYPE_DICT,
}	t_ft_json_value_type;

typedef struct s_ft_json_list_node
{
	struct s_ft_json_list_node		*next;
	union u_ft_json_value_internal	*value;
}	t_ft_json_list_node;

typedef struct s_ft_json_list
{
	t_ft_json_list_node	*head;
	t_ft_json_list_node	*tail;
}	t_ft_json_list;

typedef struct s_ft_json_dict_node
{
	struct s_ft_json_dict_node		*next;
	char							*key;
	union u_ft_json_value_internal	*value;
}	t_ft_json_dict_node;

typedef struct s_ft_json_dict
{
	t_ft_json_dict_node	*head;
	t_ft_json_dict_node	*tail;
}	t_ft_json_dict;

typedef struct s_ft_json_value_boolean
{
	t_ft_json_value_type	type;
	bool					value;
}	t_ft_json_value_boolean;

typedef struct s_ft_json_value_number
{
	t_ft_json_value_type	type;
	double					value;
}	t_ft_json_value_number;

typedef struct s_ft_json_value_string
{
	t_ft_json_value_type	type;
	char					*value;
}	t_ft_json_value_string;

typedef struct s_ft_json_value_list
{
	t_ft_json_value_type	type;
	t_ft_json_list			value;
}	t_ft_json_value_list;

typedef struct s_ft_json_value_dict
{
	t_ft_json_value_type	type;
	t_ft_json_dict			value;
}	t_ft_json_value_dict;

typedef union u_ft_json_value_internal
{
	t_ft_json_value_type	type;
	t_ft_json_value_boolean	boolean;
	t_ft_json_value_number	number;
	t_ft_json_value_string	string;
	t_ft_json_value_list	list;
	t_ft_json_value_dict	dict;
}	t_ft_json_value_internal;

typedef enum e_ft_json_token_type
{
	FT_JSON_TOKEN_TYPE_EOF,
	FT_JSON_TOKEN_TYPE_NULL,
	FT_JSON_TOKEN_TYPE_COMMA,
	FT_JSON_TOKEN_TYPE_COLON,
	FT_JSON_TOKEN_TYPE_TRUE,
	FT_JSON_TOKEN_TYPE_FALSE,
	FT_JSON_TOKEN_TYPE_BRACE_OPEN,
	FT_JSON_TOKEN_TYPE_BRACE_CLOSE,
	FT_JSON_TOKEN_TYPE_BRACKET_OPEN,
	FT_JSON_TOKEN_TYPE_BRACKET_CLOSE,
	FT_JSON_TOKEN_TYPE_NUMBER,
	FT_JSON_TOKEN_TYPE_STRING,
}	t_ft_json_token_type;

typedef struct s_ft_json_token_number
{
	t_ft_json_token_type	type;
	double					value;
}	t_ft_json_token_number;

typedef struct s_ft_json_token_string
{
	t_ft_json_token_type	type;
	char					*value;
}	t_ft_json_token_string;

typedef union u_ft_json_token
{
	t_ft_json_token_type	*type;
	t_ft_json_token_number	*number;
	t_ft_json_token_string	*string;
}	t_ft_json_token;

typedef struct s_ft_json_token_list_node
{
	struct s_ft_json_token_list_node	*next;
	void								(*free_value)(t_ft_json_token);
	t_ft_json_token						value;
}	t_ft_json_token_list_node;

typedef struct s_ft_json_token_list
{
	t_ft_json_token_list_node	*head;
	t_ft_json_token_list_node	*tail;
}	t_ft_json_token_list;

# define FT_JSON_TOKENIZER_STATE_ERROR -1
# define FT_JSON_TOKENIZER_STATE_DEFAULT 0
# define FT_JSON_TOKENIZER_STATE_KEYWORD_T 1
# define FT_JSON_TOKENIZER_STATE_KEYWORD_TR 2
# define FT_JSON_TOKENIZER_STATE_KEYWORD_TRU 3
# define FT_JSON_TOKENIZER_STATE_KEYWORD_F 4
# define FT_JSON_TOKENIZER_STATE_KEYWORD_FA 5
# define FT_JSON_TOKENIZER_STATE_KEYWORD_FAL 6
# define FT_JSON_TOKENIZER_STATE_KEYWORD_FALS 7
# define FT_JSON_TOKENIZER_STATE_KEYWORD_N 8
# define FT_JSON_TOKENIZER_STATE_KEYWORD_NU 9
# define FT_JSON_TOKENIZER_STATE_KEYWORD_NUL 10
# define FT_JSON_TOKENIZER_STATE_STRING_ANY 11
# define FT_JSON_TOKENIZER_STATE_STRING_BACKSLASH 12
# define FT_JSON_TOKENIZER_STATE_STRING_X0 13
# define FT_JSON_TOKENIZER_STATE_STRING_X1 14
# define FT_JSON_TOKENIZER_STATE_NUMBER_SIGN 15
# define FT_JSON_TOKENIZER_STATE_NUMBER_ZERO 16
# define FT_JSON_TOKENIZER_STATE_NUMBER_INTEGER 17
# define FT_JSON_TOKENIZER_STATE_NUMBER_DOT 18
# define FT_JSON_TOKENIZER_STATE_NUMBER_FRACTION 19
# define FT_JSON_TOKENIZER_STATE_NUMBER_E 20
# define FT_JSON_TOKENIZER_STATE_NUMBER_E_SIGN 21
# define FT_JSON_TOKENIZER_STATE_NUMBER_E_DIGIT 22

typedef struct s_ft_json_tokenizer_state
{
	int		state;
	void	*data;
}	t_ft_json_tokenizer_state;

typedef t_err	(*t_ft_json_tokenizer_state_function)(
					char c,
					t_ft_json_token_list *list,
					void *data,
					t_ft_json_tokenizer_state *out_next_state);

t_err	ft_json_tokenize(
			const char *str,
			t_ft_json_token_list *out);
void	ft_json_token_list_free(
			t_ft_json_token_list list);
t_err	ft_json_tokenize_default(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_keyword_t(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_keyword_tr(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_keyword_tru(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_keyword_f(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_keyword_fa(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_keyword_fal(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_keyword_fals(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_keyword_n(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_keyword_nu(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_keyword_nul(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_string_any(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_string_backslash(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_string_x0(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_string_x1(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_number_sign(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_number_zero(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_number_integer(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_number_dot(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_number_fraction(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_number_e(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_number_e_sign(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);
t_err	ft_json_tokenize_number_e_digit(
			char c,
			t_ft_json_token_list *list,
			void *data,
			t_ft_json_tokenizer_state *out_next_state);

typedef struct s_ft_json_tokenizer_state_string
{
	t_stringbuilder							*stringbuilder;
	unsigned char							x;
}	t_ft_json_tokenizer_state_string;

typedef struct s_ft_json_tokenizer_state_number
{
	double									value;
	double									current_digit;
	int										sign;
	int										exp;
	int										exp_sign;
}	t_ft_json_tokenizer_state_number;

t_err	ft_json_tokenize_add_simple_token(
			t_ft_json_token_list *list,
			t_ft_json_token_type type);
t_err	ft_json_tokenize_add_string_token(
			t_ft_json_token_list *list,
			t_ft_json_tokenizer_state_string *state);
t_err	ft_json_tokenize_add_number_token(
			t_ft_json_token_list *list,
			t_ft_json_tokenizer_state_number *state);
t_err	ft_json_tokenizer_state_string(
			void **to);
t_err	ft_json_tokenizer_state_number(
			void **to,
			char c);

t_err	ft_json_parse_value(
			t_ft_json_token_list_node **head,
			t_ft_json_value_internal *out);
t_err	ft_json_parse_list(
			t_ft_json_token_list_node **head,
			t_ft_json_value_list *out);
t_err	ft_json_parse_dict(
			t_ft_json_token_list_node **head,
			t_ft_json_value_dict *out);

bool	ft_json_parse_next_is_value(
			t_ft_json_token_type token_type);
bool	ft_json_parse_next_is_list(
			t_ft_json_token_type token_type);
bool	ft_json_parse_next_is_dict(
			t_ft_json_token_type token_type);

void	ft_json_value_internal_free(
			t_ft_json_value_internal *value);
void	ft_json_value_string_free(
			t_ft_json_value_string *value);
void	ft_json_value_list_free(
			t_ft_json_value_list *value);
void	ft_json_value_dict_free(
			t_ft_json_value_dict *value);

t_err	ft_json_parse_internal(
			const char *str,
			t_ft_json_value_internal *out);

#endif
