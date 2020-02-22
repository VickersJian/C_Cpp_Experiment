#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdbool.h>
typedef struct student student;
typedef struct target_list target_list;

void flush() {
	char c;
	while ((c = getchar()) != '\n'&&c != EOF);
}

typedef struct student {
	int Student_ID;
	char name[41];
	char course[61];
	float Usual_performance;
	float Experiment_Scores;
	float Examination_Results;
	float Total_Mark;
	student* next;
}student;

typedef struct target_list {
	int ordinal;
	student* target;
	target_list* next;
}target_list;

void output_the_list(student* head,int signal,FILE* fp) {
	student* p = head;
	switch (signal)
	{
	case 1: {
		while (p != NULL) {
			printf("%d %s %s %g %g %g %g\n", p->Student_ID, p->name, p->course, p->Usual_performance, p->Experiment_Scores, p->Examination_Results, p->Total_Mark);
			p = p->next;
		}
		break;
	}
	case 2: {
		if (fp != NULL) {
			fclose(fp);
		}
		fp = fopen(".\\data.txt", "w");
		if (fp) {
			while (p != NULL) {
				fprintf(fp,"%d %s %s %g %g %g %g\n", p->Student_ID, p->name, p->course, p->Usual_performance, p->Experiment_Scores, p->Examination_Results, p->Total_Mark);
				p = p->next;
			}
			printf("д��ɹ���\n");
			fclose(fp);
		}
		else {
			printf("�ļ�����д��ʧ�ܣ�\n");
		}
		break;
	}
	default:
		break;
	}

}

void output_target_list_sigle_item(target_list* target_student) {
	student* p = target_student->target;
	printf("%d %s %s %g %g %g %g\n", p->Student_ID, p->name, p->course, p->Usual_performance, p->Experiment_Scores, p->Examination_Results, p->Total_Mark);
}

int fill_the_target_list_of_ordinal(target_list* head) {
	int n = 0;
	while (head != NULL) {
		n++;
		head->ordinal = n;
		head = head->next;
	}
	return n;
}

void output_target_list(target_list* head, bool if_ordinal) {
	student *p = NULL;
	target_list* p_target = head;
	if (!if_ordinal) {
		while (p_target != NULL) {
			p = p_target->target;
			printf("%d %s %s %g %g %g %g\n", p->Student_ID, p->name, p->course, p->Usual_performance, p->Experiment_Scores, p->Examination_Results, p->Total_Mark);
			p_target = p_target->next;
		}
	}
	else {
		while (p_target != NULL) {
			p = p_target->target;
			printf("%d. %d %s %s %g %g %g %g\n", p_target->ordinal, p->Student_ID, p->name, p->course, p->Usual_performance, p->Experiment_Scores, p->Examination_Results, p->Total_Mark);
			p_target = p_target->next;
		}
	}
}

void operational_tips();
student* input_data(FILE* fp);
student* fill_list_data(FILE* fp);
target_list* creat_target_list(student* target);
target_list* add_target_to_list(target_list* front_target, student* target);
student* add_student_to_list(student* head, student* target);
student* delete_student_in_the_list(student* head, student* target);
bool change_student_infor(student* target);
bool delete_target_list_item(target_list** target_head_origin, int ordinal, student** student_head);
bool change_student_infor_in_target_list_item(target_list* target_head_origin, int ordinal);
target_list* find_student_by_Student_ID(student* head, int Student_ID);
target_list* find_student_by_name(student* head, char name[41]);
target_list* find_student_by_course(student* head, char course[61]);
void sort(student* head, int sort_objects);
void Excellence_or_failure_rate_of_courses(student* head, int mark, int signal);
void free_data_list(student* head);
void free_target_list(target_list* head);
void exit_program(FILE* fp, student* head);

int main() {
    bool need_to_clean=true;
	FILE* fp = NULL;
	student* head = input_data(fp);
	bool change = false;
	printf("��ӭʹ��ѧ���ɼ�����ϵͳ���밴������ʾ���в���\n");
	operational_tips();
	int signal = 0;
	scanf("%d", &signal);
	while (signal != 12) {
		switch (signal) {
		case 1: {
			while (true) {
				printf("������Ҫ��ѯ��ѧ��ѧ��(���롰q���˳�)��");
				char ch[20];
				flush();
				scanf("%s", &ch);
				printf("\n");
				if (!strcmp(ch, "q")) {
					break;
				}
				else {
					int Student_ID = atoi(ch);
					if (Student_ID > 0) {
						target_list* target_head=find_student_by_Student_ID(head, Student_ID);
						if (target_head != NULL) {
							output_target_list(target_head, false);
							printf("\n");
							free_target_list(target_head);
						}
						else {
							printf("δ�ҵ���ѧ�ŵ�ѧ��\n");
						}
					}
					else
						printf("�Ƿ����룬����������\n");
				}
			}
			break;
		}
		case 2: {
			while (true) {
				printf("������Ҫ��ѯ��ѧ������(���롰q���˳�)��");
				char name[41];
				flush();
				scanf("%s", &name);
				printf("\n");
				if (!strcmp(name, "q")) {
					break;
				}
				else {
					target_list* target_head=find_student_by_name(head, name);
					if (target_head != NULL) {
						output_target_list(target_head, false);
						printf("\n");
						free_target_list(target_head);
					}
					else {
						printf("δ�ҵ������ֵ�ѧ��\n");
					}
				}
			}
			break;
		}
		case 3: {
			while (true) {
				printf("������Ҫ��ѯ�Ŀγ�(���롰q���˳�)��");
				char course[61];
				flush();
				scanf("%s", &course);
				printf("\n");
				if (!strcmp(course, "q")) {
					break;
				}
				else {
					target_list* target_head=find_student_by_course(head, course);
					if (target_head != NULL) {
						output_target_list(target_head, false);
						printf("\n");
						free_target_list(target_head);
					}
					else {
						printf("δ�ҵ��иÿγ̵�ѧ��\n");
					}
				}
			}
			break;
		}
		case 4: {
			student temp;
			printf("������ѧ����Ϣ(��ѧ�ţ��������γ�����ƽʱ�ɼ���ʵ��ɼ������Գɼ��������ɼ��ĸ�ʽ���룬�����롰q���˳�)��\n\n");
			while (true) {
				if (scanf("%d%s%s%f%f%f%f", &temp.Student_ID, &temp.name, &temp.course, &temp.Usual_performance, &temp.Experiment_Scores, &temp.Examination_Results, &temp.Total_Mark) != 7) {
					if (getchar() == 'q') {
						break;
					}
					printf("�޷����ѧ����Ϣ�������ʽ�������ڷǷ����룬�����������q���˳�\n\n");
				}
				else {
					head = add_student_to_list(head, &temp);
					change = true;
					printf("���������ѧ����Ϣ(�����롰q���˳�)��\n\n");
				}
			}
			break;
		}
		case 5: {
			int Student_ID;
			char name[41];
			int ordinal=0;
			target_list* target_head=NULL;
			bool if_all_delete = false;
			printf("��������Ҫɾ����ѧ����ѧ�Ż�����(���롰q���˳�)��\n");
			while (true) {
				if (scanf("%d", &Student_ID) == 1) {
					target_head = find_student_by_Student_ID(head, Student_ID);
					if (target_head != NULL) {
						fill_the_target_list_of_ordinal(target_head);
						output_target_list(target_head, true);
						printf("��������Ҫɾ����ѧ����Ϣ�����(���롱q���˳�)��");
						while (true) {
							if (scanf("%d", &ordinal) != 1) {
								if (getchar() == 'q') {
									flush();
									break;
								}
								else {
									flush();
									printf("�Ƿ����룬����������\n");
								}
							}
							else {
								if (delete_target_list_item(&target_head, ordinal, &head)) {
									change = true;
									printf("ɾ���ɹ���\n");
									fill_the_target_list_of_ordinal(target_head);
									if (target_head != NULL) {
										output_target_list(target_head, true);
									}
									else {
										printf("��ѧ����Ϣ��ȫ��ɾ��\n");
										if_all_delete = true;
										break;
									}
								}
								else {
									printf("�����ڸ���ŵ�ѧ����Ϣ������������\n");
								}
							}
						}
					}
				}
				else {
					scanf("%s", name);
					if (strcmp(name, "q") == 0) {
						break;
					}
					target_head = find_student_by_name(head, name);
					if (target_head != NULL) {
						fill_the_target_list_of_ordinal(target_head);
						output_target_list(target_head, true);
						printf("��������Ҫɾ����ѧ����Ϣ�����(���롱q���˳�)��");
						while (true) {
							if (scanf("%d", &ordinal) != 1) {
								if (getchar() == 'q') {
									flush();
									break;
								}
								else {
									flush();
									printf("�Ƿ����룬����������\n");
								}
							}
							else {
								if (delete_target_list_item(&target_head, ordinal, &head)) {
									change = true;
									printf("ɾ���ɹ���\n");
									fill_the_target_list_of_ordinal(target_head);
									if (target_head != NULL) {
										output_target_list(target_head, true);
									}
									else {
										printf("��ѧ����Ϣ��ȫ��ɾ��\n");
										if_all_delete = true;
										break;
									}
								}
								else {
									printf("�����ڸ���ŵ�ѧ����Ϣ������������\n");
								}
							}
						}
					}
				}
				if (target_head == NULL&&if_all_delete==false) {
					printf("�����ڸ���Ϣ��ѧ��������������\n");
				}
				if (if_all_delete==true&&head!=NULL) {
					printf("�����������Ҫɾ����ѧ����ѧ�Ż�����(���롰q���˳�)��\n");
					if_all_delete = false;
				}
				else if(head==NULL){
					printf("ȫ��ѧ����Ϣ����ɾ����\n");
					break;
				}
				else {
					printf("��������Ҫɾ����ѧ����ѧ�Ż�����(���롰q���˳�)��\n");
				}
			}
			break;
		}
		case 6: {
			int Student_ID;
			char name[41];
			int ordinal = 0;
			target_list* target_head = NULL;
			bool if_all_delete = false;
			printf("��������Ҫ�޸ĵ�ѧ����ѧ�Ż�����(���롰q���˳�)��\n");
			while (true) {
				if (scanf("%d", &Student_ID) == 1) {
					target_head = find_student_by_Student_ID(head, Student_ID);
					if (target_head != NULL) {
						fill_the_target_list_of_ordinal(target_head);
						output_target_list(target_head, true);
						printf("��������Ҫ�޸ĵ�ѧ����Ϣ�����(���롱q���˳�)��");
						while (true) {
							if (scanf("%d", &ordinal) != 1) {
								if (getchar() == 'q') {
									flush();
									break;
								}
								else {
									flush();
									printf("�Ƿ����룬����������\n");
								}
							}
							else {
								if (change_student_infor_in_target_list_item(target_head, ordinal)) {
									change = true;
									fill_the_target_list_of_ordinal(target_head);
									if (target_head != NULL) {
										output_target_list(target_head, true);
									}

								}
								else {
									printf("�����ڸ���ŵ�ѧ����Ϣ������������\n");
								}
							}
						}
					}
				}
				else {
					scanf("%s", name);
					if (strcmp(name, "q") == 0) {
						break;
					}
					target_head = find_student_by_name(head, name);
					if (target_head != NULL) {
						fill_the_target_list_of_ordinal(target_head);
						output_target_list(target_head, true);
						printf("��������Ҫ�޸ĵ�ѧ����Ϣ�����(���롱q���˳�)��");
						while (true) {
							if (scanf("%d", &ordinal) != 1) {
								if (getchar() == 'q') {
									flush();
									break;
								}
								else {
									flush();
									printf("�Ƿ����룬����������\n");
								}
							}
							else {
								if (change_student_infor_in_target_list_item(target_head, ordinal)) {
									change = true;
									fill_the_target_list_of_ordinal(target_head);
									if (target_head != NULL) {
										output_target_list(target_head, true);
									}
								}
								else {
									printf("�����ڸ���ŵ�ѧ����Ϣ������������\n");
								}
							}
						}
					}
				}
				if(target_head==NULL) {
					printf("�����ڸ���Ϣ��ѧ��������������\n");
				}
				printf("��������Ҫ�޸ĵ�ѧ����ѧ�Ż�����(���롰q���˳�)��\n");
			}
			break;
		}
		case 7: {
			sort(head, 1);
			change = true;
			printf("������ɣ�\n��Ҫ�������Ļ����(Y\\N)��(������Ҫ�϶��ʱ�䣡)");
			char c;
			flush();
			scanf("%c",&c);
			if(c=='Y'||c=='y'){
                output_the_list(head,1,NULL);
                printf("�����ɣ��밴��ʾ�������в���\n\n");
                operational_tips();
                need_to_clean=false;
			}
			break;
		}
		case 8: {
			sort(head, 2);
			change = true;
			printf("������ɣ�\n��Ҫ�������Ļ����(Y\\N)��(������Ҫ�϶��ʱ�䣡)");
			char c;
			flush();
			scanf("%c",&c);
			if(c=='Y'||c=='y'){
                output_the_list(head,1,NULL);
                printf("�����ɣ��밴��ʾ�������в���\n\n");
                operational_tips();
                need_to_clean=false;
			}
			break;
		}
		case 9: {
			sort(head, 3);
			break;
		}
		case 10: {
			Excellence_or_failure_rate_of_courses(head,90,1);
			break;
		}
		case 11: {
			Excellence_or_failure_rate_of_courses(head, 60, 2);
			break;
		}
		default:{
                printf("��������Ч�����������롣\n");
                need_to_clean=false;
			}
		}
        if(need_to_clean){
            system("cls");
            operational_tips();
        }
        need_to_clean=true;
		flush();
		if (scanf("%d", &signal) != 1)signal = 0;
	}
	if (change == true) {
		printf("�Ƿ����и��ı��浽data.txt�У�(Y/N)\n");
		char if_out_put_to_file;
		flush();
		scanf("%c", &if_out_put_to_file);
		if (if_out_put_to_file == 'Y' || if_out_put_to_file == 'y') {
			output_the_list(head, 2, fp);
		}
	}
	exit_program(fp, head);
	return 0;
}

void operational_tips() {
	printf("\n1.  ��ѧ��ѧ�Ų�ѯѧ����Ϣ��\n");
	printf("2.  ��ѧ��������ѯѧ����Ϣ��\n");
	printf("3.  ���γ�����ѯѧ����Ϣ��\n");
	printf("4.  ���ѧ����Ϣ��\n");
	printf("5.  ɾ��ѧ����Ϣ��\n");
	printf("6.  �޸�ѧ����Ϣ��\n");
	printf("7.  �������ɼ�����\n");
	printf("8.  �����Գɼ�����\n");
	printf("9.  ��ѯ�γ̵���߷֡���ͷּ���Ӧ��ѧ����Ϣ��\n");
	printf("10. ��ѯ�γ������ʡ�\n");
	printf("11. ��ѯ�γ̲������ʡ�\n");
	printf("12. �˳�ϵͳ��\n\n");
}

student* input_data(FILE* fp) {
	student* head = NULL;
	fp = fopen(".\\data.txt", "r");
	if (fp) {
		head = fill_list_data(fp);
		fseek(fp, 0, SEEK_SET);
	}
	else {
		printf("�ļ��򿪴����ļ�data.txt������");
		exit(-1);
	}
	return head;
}

student* fill_list_data(FILE* fp) {
	student *head = NULL;
	student data;
	data.next=NULL;
	student *temp = NULL;
	student *p = NULL;
	int n = 0;
	while (!feof(fp)) {
		n++;
		fscanf(fp, "%d%s%s%f%f%f%f", &data.Student_ID, data.name, data.course, &data.Usual_performance, &data.Experiment_Scores, &data.Examination_Results, &data.Total_Mark);
		p = (student*)malloc(sizeof(student));
		*p=data;
		if (n == 1) {
			head = p;
			temp = p;
		}
		else {
			temp->next = p;
			temp = p;
		}
	}
	return head;
}

target_list* creat_target_list(student* target) {
	target_list* target_head = (target_list*)malloc(sizeof(target_list));
	target_head->target = target;
	target_head->next = NULL;
	return target_head;
}

target_list* add_target_to_list(target_list* front_target, student* target) {
	target_list* p = (target_list*)malloc(sizeof(target_list));
	p->target = target;
	p->next = NULL;
	front_target->next = p;
	return p;
}

target_list* find_student_by_Student_ID(student* head, int Student_ID) {
	student* target = NULL;
	target_list* target_head = NULL;
	target_list* front_target = NULL;
	int n = 0;
	while (head != NULL) {
		if (head->Student_ID == Student_ID) {
			n++;
			if (n == 1) {
				target_head = creat_target_list(head);
				front_target = target_head;
			}
			else {
				front_target = add_target_to_list(front_target, head);
			}
		}
		head = head->next;
	}
	return target_head;
}

target_list* find_student_by_name(student* head, char name[41]) {
	student* target = NULL;
	target_list* target_head = NULL;
	target_list* front_target = NULL;
	int n = 0;
	while (head != NULL) {
		if (strcmp(head->name, name) == 0) {
			n++;
			if (n == 1) {
				target_head = creat_target_list(head);
				front_target = target_head;
			}
			else {
				front_target = add_target_to_list(front_target, head);
			}
		}
		head = head->next;
	}
	return target_head;
}

target_list* find_student_by_course(student* head, char course[61]) {
	student* target = NULL;
	target_list* target_head = NULL;
	target_list* front_target = NULL;
	int n = 0;
	while (head != NULL) {
		if (strcmp(head->course, course) == 0) {
			n++;
			if (n == 1) {
				target_head = creat_target_list(head);
				front_target = target_head;
			}
			else {
				front_target = add_target_to_list(front_target, head);
			}
		}
		head = head->next;
	}
	return target_head;
}

student* add_student_to_list(student* head, student* target) {
	student* p = (student*)malloc(sizeof(student));
	*p=*target;
	p->next = head;
	return p;
}

student* delete_student_in_the_list(student* head, student* target) {
	student* front_target = NULL;
	student* t = head;
	bool if_find_target = false;
	while (head != NULL) {
		if (target == head) {
			if_find_target = true;
			break;
		}
		front_target = head;
		head = head->next;
	}
	if (if_find_target) {
		if (front_target != NULL) {
			front_target->next = target->next;
			free(target);
		}
		else {
			t = target->next;
			free(target);
		}
	}
	return t;
}

bool delete_target_list_item(target_list** target_head_origin, int ordinal,student** student_head) {
	target_list* target_head= *target_head_origin;
	target_list* front_target = NULL;
	target_list* target_list_item = NULL;
	bool if_find_target = false;
	while (target_head != NULL) {
		if (ordinal == target_head->ordinal) {
			target_list_item = target_head;
			if_find_target = true;
			break;
		}
		front_target = target_head;
		target_head = target_head->next;
	}
	if (if_find_target == true) {
		if (front_target != NULL) {
			delete_student_in_the_list(*student_head, target_list_item->target);
			front_target->next = target_list_item->next;
			free(target_list_item);
		}
		else {
			*student_head = delete_student_in_the_list(*student_head, target_list_item->target);
			*target_head_origin = target_list_item->next;
			free(target_head);
		}
	}
	return if_find_target;
}

bool change_student_infor(student* target) {
	bool if_success_change = false;
	student temp;
	printf("������ѧ����Ϣ(��ѧ�ţ��������γ�����ƽʱ�ɼ���ʵ��ɼ������Գɼ��������ɼ��ĸ�ʽ���룬�����롰q���˳�)��\n\n");
	while (true) {
		if (scanf("%d%s%s%f%f%f%f", &temp.Student_ID, &temp.name, &temp.course, &temp.Usual_performance, &temp.Experiment_Scores, &temp.Examination_Results, &temp.Total_Mark) != 7) {
			if (getchar() == 'q') {
				break;
			}
			printf("�޷��޸�ѧ����Ϣ�������ʽ�������ڷǷ����룬�����������q���˳�\n\n");
			flush();
		}
		else {
			temp.next = target->next;
			*target = temp;
			printf("�޸ĳɹ���\n");
			if_success_change = true;
			break;
		}
	}
	return if_success_change;
}

bool change_student_infor_in_target_list_item(target_list* target_head_origin, int ordinal) {
	target_list* target_head = target_head_origin;
	target_list* target_list_item = NULL;
	bool if_find_target = false;
	while (target_head != NULL) {
		if (ordinal == target_head->ordinal) {
			target_list_item = target_head;
			if_find_target = true;
			break;
		}
		target_head = target_head->next;
	}
	if (if_find_target == true) {
		change_student_infor(target_list_item->target);
	}
	return if_find_target;
}

void sort(student* head,int sort_objects) {
	switch (sort_objects){
	case 1: {
		for (student* i = head; i != NULL; i=i->next) {
			for (student* j = head; j->next != NULL; j=j->next) {
				if (j->Total_Mark < j->next->Total_Mark) {
					student* p_t_1 = j;
					student* p_t_2 = j->next;
					student* p_t_3 = j->next->next;
					student temp;
					temp = *p_t_1;
					*p_t_1 = *p_t_2;
					*p_t_2 = temp;
					p_t_1->next = p_t_2;
					p_t_2->next = p_t_3;
				}
			}
		}
		break;
	}
	case 2: {
		for (student* i = head; i != NULL; i = i->next) {
			for (student* j = head; j->next != NULL; j = j->next) {
				if (j->Examination_Results < j->next->Examination_Results) {
					student* p_t_1 = j;
					student* p_t_2 = j->next;
					student* p_t_3 = j->next->next;
					student temp;
					temp = *p_t_1;
					*p_t_1 = *p_t_2;
					*p_t_2 = temp;
					p_t_1->next = p_t_2;
					p_t_2->next = p_t_3;
				}
			}
		}
		break;
	}
	case 3: {
		char course[61];
		printf("������γ���(���롰q���˳�)��\n");
		while (true) {
			scanf("%s", &course);
			if (strcmp(course, "q") == 0) {
				break;
			}
			target_list* target_list_head = find_student_by_course(head, course);
			if (target_list_head != NULL) {
				target_list* max = target_list_head;
				target_list* min = target_list_head;
				for (target_list* i=target_list_head; i != NULL; i = i->next) {
					if (max->target->Total_Mark < i->target->Total_Mark) {
						max = i;
					}
				}
				for (target_list* i=target_list_head; i != NULL; i = i->next) {
					if (min->target->Total_Mark > i->target->Total_Mark) {
						min = i;
					}
				}
				printf("�ɼ���ߵ�ѧ����");
				output_target_list_sigle_item(max);
				printf("�ɼ���͵�ѧ����");
				output_target_list_sigle_item(min);
				printf("���������γ�����ѯ(���롰q���˳�)��\n");
			}
			else {
				printf("δ�ҵ��ÿγ̣�����������\n\n");
			}
		}
		break;
	}
	default:
		break;
	}
}

void Excellence_or_failure_rate_of_courses(student* head,int mark,int signal) {
	char course[61];
	printf("������γ���(���롰q���˳�)��\n");
	while (true) {
		scanf("%s", &course);
		if (strcmp(course, "q") == 0) {
			break;
		}
		target_list* target_list_head = find_student_by_course(head, course);
		if (target_list_head != NULL) {
			int total = fill_the_target_list_of_ordinal(target_list_head);
			int num = 0;
			switch (signal)
			{
			case 1: {
				for (target_list* i = target_list_head; i != NULL; i = i->next) {
					if (i->target->Total_Mark >= mark) {
						num++;
					}
				}
				printf("������Ϊ %g %%\n", num*100.0 / total);
				break;
			}
			case 2: {
				for (target_list* i = target_list_head; i != NULL; i = i->next) {
					if (i->target->Total_Mark < mark) {
						num++;
					}
				}
				printf("��������Ϊ %g %%\n", num*100.0 / total);
				break;
			}
			default:
				break;
			}
			printf("\n���������γ�����ѯ(���롰q���˳�)��\n");
		}
		else {
			printf("δ�ҵ��ÿγ̣�����������\n\n");
		}
	}
}

void free_data_list(student* head) {
	student* temp;
	if (head != NULL)
		while (head->next != NULL) {
			temp = head->next;
			free(head);
			head = temp;
		}
}

void free_target_list(target_list* head) {
	target_list* temp;
	if (head != NULL)
		while (head->next != NULL) {
			temp = head->next;
			free(head);
			head = temp;
		}
}

void exit_program(FILE* fp, student* head) {
	if (fp != NULL) {
		fclose(fp);
	}
	free_data_list(head);
	printf("�����������ӭ�ٴ�ʹ�ã�");
}
