/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_Manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:28:44 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/20 11:41:25 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include <stdbool.h>
#include <stddef.h>

typedef	struct	s_contact
{
	int     id;
	char	*name;
	char	*phone;
	char	*email;
	char	*city;
	char	*address;
}				t_contact;

typedef	struct	s_contact_db
{
	int			max_id;
	size_t		count;
	t_contact	*contacts[1000];
}				t_contact_db;

bool load_contacts_from_file(const char *filename, t_contact_db *db);

bool save_contacts_to_file(const char *filename, const t_contact_db *db);

bool validate_id(const char *str, int *id, const t_contact_db *db);
bool validate_name(const char *str);
bool validate_city(const char *str);
bool validate_phone(const char *str);
bool validate_email(const char *str);

char *trim_whitespace(char *str);
char *strdup_trimmed(const char *str);
void free_contact(t_contact *contact);
t_contact *create_contact_from_line(const char *line, const t_contact_db *db);

t_contact *find_contact_by_id(const t_contact_db *db, int id);
void add_contact(t_contact_db *db, t_contact *contact);
bool delete_contact(t_contact_db *db, int id);
void update_contact(t_contact *contact, const t_contact *new_data);


void search_contacts_by_name(const t_contact_db *db, const char *substr);
void search_contacts_by_city(const t_contact_db *db, const char *substr);

void contact_manager_menu(t_contact_db *db, const char *filename);
void print_contact(const t_contact *contact);
void list_all_contacts(const t_contact_db *db);

#endif