typedef struct Node 
{
	int data;
	struct Node *next;
	struct Node *prev;
} t_Node;

int main(void)
{
	t_Node *first = NULL;
	t_Node *tmp = first;
	int i = 1;
	while (i < 8)
	{
		tmp->data = i;
		tmp = tmp->next;
		i++;
	}
	t_Node *link_first = first;
	printf("%d", link_first->data); // tete  = 1
	link_first = link_first->next;
	printf("%d", link_first->data); // connexion de 1 = 2 et 3
	link_first->prev = first; // relier le 2 au 1
	printf("%d <-> %d", link_first->prev->data, link_first->data); // doit s'afficher 1 <-> 2
	link_first = link_first->next;
	link_first->prev = first;
	printf("%d <-> %d", link_first->prev->data, link_first->data); // doit s'afficher 1 <-> 3
	/*
	t_Node *link_second = first->next; // demi tete = 2
	printf("%d", link_second->data); // doit s'afficher 2
	link_second = link_second->next->next; // on cherche 4
	link_second->prev = first->next; // on relie 4 a 2
	link_second = link_second->next; // on cherche 5
	link_second->prev = first->next; // on relie 5 a 2
	t_Node *bis_link_second = first->next->next; // demi tete = 3
	link_second = link_second->next; // on cherche 6
	link_second->prev = bis_link_second; // on relie 6  a 3
	link_second = link_second->next; // on cherche 7
	link_second->prev = bis_link_second; // on relie 7 a 3
	printf("%d", link_first->prev->data); // 2
	*/
}

/*
Idee :
le 2 et 3 reconnaissent leur precedent
ainsi de suite
    1
  2  3
 4 5 6 7

 Sauvegarder les donnes qui lient puis relier les prochaines nodes 
 avec un pointeur prev sur l'intersection correspondante.
 */
