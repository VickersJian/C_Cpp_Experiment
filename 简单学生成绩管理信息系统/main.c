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
			printf("写入成功！\n");
			fclose(fp);
		}
		else {
			printf("文件错误，写入失败！\n");
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
	printf("欢迎使用学生成绩管理系统，请按以下提示进行操作\n");
	operational_tips();
	int signal = 0;
	scanf("%d", &signal);
	while (signal != 12) {
		switch (signal) {
		case 1: {
			while (true) {
				printf("请输入要查询的学生学号(输入“q”退出)：");
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
							printf("未找到该学号的学生\n");
						}
					}
					else
						printf("非法输入，请重新输入\n");
				}
			}
			break;
		}
		case 2: {
			while (true) {
				printf("请输入要查询的学生姓名(输入“q”退出)：");
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
						printf("未找到该名字的学生\n");
					}
				}
			}
			break;
		}
		case 3: {
			while (true) {
				printf("请输入要查询的课程(输入“q”退出)：");
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
						printf("未找到有该课程的学生\n");
					}
				}
			}
			break;
		}
		case 4: {
			student temp;
			printf("请输入学生信息(按学号，姓名，课程名，平时成绩，实验成绩，考试成绩，总评成绩的格式输入，或输入“q”退出)：\n\n");
			while (true) {
				if (scanf("%d%s%s%f%f%f%f", &temp.Student_ID, &temp.name, &temp.course, &temp.Usual_performance, &temp.Experiment_Scores, &temp.Examination_Results, &temp.Total_Mark) != 7) {
					if (getchar() == 'q') {
						break;
					}
					printf("无法添加学生信息：输入格式错误或存在非法输入，请重新输入或“q”退出\n\n");
				}
				else {
					head = add_student_to_list(head, &temp);
					change = true;
					printf("请继续输入学生信息(或输入“q“退出)：\n\n");
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
			printf("请输入需要删除的学生的学号或姓名(输入“q”退出)：\n");
			while (true) {
				if (scanf("%d", &Student_ID) == 1) {
					target_head = find_student_by_Student_ID(head, Student_ID);
					if (target_head != NULL) {
						fill_the_target_list_of_ordinal(target_head);
						output_target_list(target_head, true);
						printf("请输入需要删除的学生信息的序号(输入”q“退出)：");
						while (true) {
							if (scanf("%d", &ordinal) != 1) {
								if (getchar() == 'q') {
									flush();
									break;
								}
								else {
									flush();
									printf("非法输入，请重新输入\n");
								}
							}
							else {
								if (delete_target_list_item(&target_head, ordinal, &head)) {
									change = true;
									printf("删除成功！\n");
									fill_the_target_list_of_ordinal(target_head);
									if (target_head != NULL) {
										output_target_list(target_head, true);
									}
									else {
										printf("该学生信息已全部删除\n");
										if_all_delete = true;
										break;
									}
								}
								else {
									printf("不存在该序号的学生信息，请重新输入\n");
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
						printf("请输入需要删除的学生信息的序号(输入”q“退出)：");
						while (true) {
							if (scanf("%d", &ordinal) != 1) {
								if (getchar() == 'q') {
									flush();
									break;
								}
								else {
									flush();
									printf("非法输入，请重新输入\n");
								}
							}
							else {
								if (delete_target_list_item(&target_head, ordinal, &head)) {
									change = true;
									printf("删除成功！\n");
									fill_the_target_list_of_ordinal(target_head);
									if (target_head != NULL) {
										output_target_list(target_head, true);
									}
									else {
										printf("该学生信息已全部删除\n");
										if_all_delete = true;
										break;
									}
								}
								else {
									printf("不存在该序号的学生信息，请重新输入\n");
								}
							}
						}
					}
				}
				if (target_head == NULL&&if_all_delete==false) {
					printf("不存在该信息的学生，请重新输入\n");
				}
				if (if_all_delete==true&&head!=NULL) {
					printf("请继续输入需要删除的学生的学号或姓名(输入“q”退出)：\n");
					if_all_delete = false;
				}
				else if(head==NULL){
					printf("全部学生信息都已删除！\n");
					break;
				}
				else {
					printf("请输入需要删除的学生的学号或姓名(输入“q”退出)：\n");
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
			printf("请输入需要修改的学生的学号或姓名(输入“q”退出)：\n");
			while (true) {
				if (scanf("%d", &Student_ID) == 1) {
					target_head = find_student_by_Student_ID(head, Student_ID);
					if (target_head != NULL) {
						fill_the_target_list_of_ordinal(target_head);
						output_target_list(target_head, true);
						printf("请输入需要修改的学生信息的序号(输入”q“退出)：");
						while (true) {
							if (scanf("%d", &ordinal) != 1) {
								if (getchar() == 'q') {
									flush();
									break;
								}
								else {
									flush();
									printf("非法输入，请重新输入\n");
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
									printf("不存在该序号的学生信息，请重新输入\n");
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
						printf("请输入需要修改的学生信息的序号(输入”q“退出)：");
						while (true) {
							if (scanf("%d", &ordinal) != 1) {
								if (getchar() == 'q') {
									flush();
									break;
								}
								else {
									flush();
									printf("非法输入，请重新输入\n");
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
									printf("不存在该序号的学生信息，请重新输入\n");
								}
							}
						}
					}
				}
				if(target_head==NULL) {
					printf("不存在该信息的学生，请重新输入\n");
				}
				printf("请输入需要修改的学生的学号或姓名(输入“q”退出)：\n");
			}
			break;
		}
		case 7: {
			sort(head, 1);
			change = true;
			printf("排序完成！\n需要输出到屏幕上吗？(Y\\N)：(可能需要较多的时间！)");
			char c;
			flush();
			scanf("%c",&c);
			if(c=='Y'||c=='y'){
                output_the_list(head,1,NULL);
                printf("输出完成，请按提示继续进行操作\n\n");
                operational_tips();
                need_to_clean=false;
			}
			break;
		}
		case 8: {
			sort(head, 2);
			change = true;
			printf("排序完成！\n需要输出到屏幕上吗？(Y\\N)：(可能需要较多的时间！)");
			char c;
			flush();
			scanf("%c",&c);
			if(c=='Y'||c=='y'){
                output_the_list(head,1,NULL);
                printf("输出完成，请按提示继续进行操作\n\n");
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
                printf("该输入无效，请重新输入。\n");
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
		printf("是否将所有更改保存到data.txt中？(Y/N)\n");
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
	printf("\n1.  按学生学号查询学生信息。\n");
	printf("2.  按学生姓名查询学生信息。\n");
	printf("3.  按课程名查询学生信息。\n");
	printf("4.  添加学生信息。\n");
	printf("5.  删除学生信息。\n");
	printf("6.  修改学生信息。\n");
	printf("7.  按总评成绩排序。\n");
	printf("8.  按考试成绩排序。\n");
	printf("9.  查询课程的最高分、最低分及相应的学生信息。\n");
	printf("10. 查询课程优秀率。\n");
	printf("11. 查询课程不及格率。\n");
	printf("12. 退出系统。\n\n");
}

student* input_data(FILE* fp) {
	student* head = NULL;
	fp = fopen(".\\data.txt", "r");
	if (fp) {
		head = fill_list_data(fp);
		fseek(fp, 0, SEEK_SET);
	}
	else {
		printf("文件打开错误，文件data.txt不存在");
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
	printf("请输入学生信息(按学号，姓名，课程名，平时成绩，实验成绩，考试成绩，总评成绩的格式输入，或输入“q”退出)：\n\n");
	while (true) {
		if (scanf("%d%s%s%f%f%f%f", &temp.Student_ID, &temp.name, &temp.course, &temp.Usual_performance, &temp.Experiment_Scores, &temp.Examination_Results, &temp.Total_Mark) != 7) {
			if (getchar() == 'q') {
				break;
			}
			printf("无法修改学生信息：输入格式错误或存在非法输入，请重新输入或“q”退出\n\n");
			flush();
		}
		else {
			temp.next = target->next;
			*target = temp;
			printf("修改成功！\n");
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
		printf("请输入课程名(输入“q”退出)：\n");
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
				printf("成绩最高的学生：");
				output_target_list_sigle_item(max);
				printf("成绩最低的学生：");
				output_target_list_sigle_item(min);
				printf("请继续输入课程名查询(输入“q”退出)：\n");
			}
			else {
				printf("未找到该课程，请重新输入\n\n");
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
	printf("请输入课程名(输入“q”退出)：\n");
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
				printf("优秀率为 %g %%\n", num*100.0 / total);
				break;
			}
			case 2: {
				for (target_list* i = target_list_head; i != NULL; i = i->next) {
					if (i->target->Total_Mark < mark) {
						num++;
					}
				}
				printf("不及格率为 %g %%\n", num*100.0 / total);
				break;
			}
			default:
				break;
			}
			printf("\n请继续输入课程名查询(输入“q”退出)：\n");
		}
		else {
			printf("未找到该课程，请重新输入\n\n");
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
	printf("程序结束，欢迎再次使用！");
}
