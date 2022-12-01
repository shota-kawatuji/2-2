#include <stdio.h>
#include <stdlib.h>

//�P�������X�g�̍\���̂̒�`
typedef struct cell
{
	int val;
	struct cell* next;
}CELL;

void Create(CELL* currentCell, int val);
void Index(CELL* head);

int main()
{

	int val;

	//�擪�̃Z����錾
	CELL head;
	head.next = nullptr;

	while (true)
	{
		printf("��������͂��Ă�������\n");

		scanf_s("%d", &val);

		//�Ō���Ƀ��X�g��ǉ�
		Create(&head, val);

		//���X�g�ꗗ�̕\��
		Index(&head);
	}
	return 0;
}


//�Z����V�K�쐬����֐�
void Create(CELL* currentCell, int val)
{
	CELL* newCell;

	//�V�K�쐬����Z�����̃��������m�ۂ���
	newCell = (CELL*)malloc(sizeof(CELL));

	if (newCell)
	{
		newCell->val = val;
		newCell->next = nullptr;
	}

	//�Ō�(�ŐV)�̃Z���̃A�h���X��1�ڂ̏����͈������玝���Ă���
	//���X�g�̂����ŏ��̃Z���̃A�h���X���Y������
	while (currentCell->next != nullptr)
	{
		currentCell = currentCell->next;
	}

	currentCell->next = newCell;
}

void Index(CELL* head)
{
	printf("{");
	while (head->next != nullptr)
	{
		head = head->next;
		printf("%d,", head->val);
	}
	printf("}\n\n");
}
