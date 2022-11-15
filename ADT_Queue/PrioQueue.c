/* File : prioqueue.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */

#include "PrioQueue.h"
#include <stdio.h>
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty(PrioQueue Q)
{
	/* Mengirim true jika Q kosong: lihat definisi di atas */
	return Head(Q) == Nil && Tail(Q) == Nil;
}
boolean IsFull(PrioQueue Q)
{
	/* Mengirim true jika tabel penampung elemen Q sudah penuh */
	/* yaitu mengandung elemen sebanyak MaxEl */
	return ((Head(Q) == 0) && (Tail(Q) == MaxEl(Q) - 1)) || (Tail(Q) == Head(Q) - 1);
}
boolean isThereExp(PrioQueue Q)
{
	/* Mengirim true jika dalam queue ada yang expired */
	return Time(Elmt(Q, Head(Q))) < 1;
}
boolean searchMkn(PrioQueue Q, MAKANAN m)
{
	/* Mengirimkan true jika makanan terdapat dalam queue */
	if (IsEmpty(Q))
	{
		return false;
	}
	else
	{
		int i = Head(Q);
		while (i != Tail(Q) && Elmt(Q, i).id != m.id)
		{
			i++;
			if (i == Q.MaxEl)
			{
				i = 0;
			}
		}
		// i == tail atau elemennya udah sama
		return Elmt(Q, i).id == m.id;
	}
}
int NBElmt(PrioQueue Q)
{
	/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

	int lin = (Tail(Q) - Head(Q)) + 1;
	int lantarab;
	if (IsEmpty(Q)) //
		return 0;
	else if (Head(Q) == Tail(Q))
	{
		return 1;
	}
	else if (Head(Q) < Tail(Q))
	{
		return lin;
	}
	else
	{
		lantarab = Head(Q) - Tail(Q) - 1;
		return MaxEl(Q) - lantarab;
	}
}

/* *** Kreator *** */
void MakeEmpty(PrioQueue *Q, int Max)
{
	/* I.S. sembarang */
	/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
	/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
	/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
	/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

	(*Q).T = (MAKANAN *)malloc((Max) * sizeof(MAKANAN) * sizeof(int)); // alokasi
	if ((*Q).T != NULL)
	{
		MaxEl(*Q) = Max;
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	}
	else
	{
		MaxEl(*Q) = 0;
	}
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueue *Q)
{
	/* Proses: Mengembalikan memori Q */
	/* I.S. Q pernah dialokasi */
	/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

	MaxEl(*Q) = 0;
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
	free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue(PrioQueue *Q, MAKANAN X)
{
	/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
	/* I.S. Q mungkin kosong, tabel penampung elemen Q BISA penuh */
	/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
			TAIL "maju" dengan mekanisme circular buffer; */
	int i, h;
	if (Time(X) != 0 && ! IsFull(*Q))
	{
		// if (IsFull(*Q))
		// {
		// }
		if (IsEmpty(*Q))
		{
			Head(*Q) = 0;
			Tail(*Q) = 0;
			InfoTail(*Q) = X;
		}
		else
		{
			i = Tail(*Q);
			Tail(*Q) = (Tail(*Q) + 1) % MaxEl(*Q);
			h = (Head(*Q) - 1) % MaxEl(*Q);
			// if (Head(*Q)==-1){
			// 	h =  MaxEl(*Q)-1;
			// }
			while (i != h && Time(X) <= Time(Elmt(*Q, i)))
			{
				(*Q).T[((i + 1) % MaxEl(*Q))] = (*Q).T[i];
				i--;
				if (i == (-1))
				{
					i = MaxEl(*Q) - 1;
				}
				// PrintPrioQueue(*Q);
			}
			(*Q).T[((i + 1) % MaxEl(*Q))] = X;
		}
	}
}

void Dequeue(PrioQueue *Q, MAKANAN *X)
{
	/* Proses: Menghapus X pada Q dengan aturan FIFO */
	/* I.S. Q tidak mungkin kosong */
	/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
			Q mungkin kosong */
	if (!IsEmpty(*Q))
	{
		*X = InfoHead(*Q);
		if (NBElmt(*Q) == 1)
		{
			Head(*Q) = Nil;
			Tail(*Q) = Nil;
		}
		else
		{
			Head(*Q) = (Head(*Q) + 1) % MaxEl(*Q);
		}
	}
}

void DequeueExp(PrioQueue *Q, MAKANAN *X)
{
	/* Proses: Menghapus X pada Q dengan aturan FIFO Jika ada yang exp dalam queue */
	/* I.S. Q tidak mungkin kosong */
	/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
			Q mungkin kosong */

	// Cari apakah ada yang harus di-dequeue karena sudah exp
	while (isThereExp(*Q))
	{
		Dequeue(Q, X);
	}
}

void removeFromInventory(PrioQueue *Q, MAKANAN m){
	/* Proses: Menghapus m pada Q dengan aturan yang paling mendekati expired dimulai dari head 
	hingga menemukan m lalu dihapus */
	/* I.S. Q tidak mungkin kosong */
	/* F.S. m ter-dequeue (hapus) dari Q dan Q tetap teratur dengan mekanisme circular buffer
			Q mungkin menjadi kosong */
	if (! IsEmpty(*Q))
	{
		MAKANAN temp;
		int idx;
		int tail;
		int i = Head(*Q);
		while (Elmt(*Q, i).id != m.id)
		{
			i++;
			if (i == Q->MaxEl)
			{
				i = 0;
			}
		}
		// i = index dengan Elmt(*Q, i).id == m.id 
		if (i==Head(*Q)){
			Dequeue(Q, &temp);
		}
		else if (i != Tail(*Q)){
			tail = Tail(*Q);
			// Tail(*Q) = (Tail(*Q)-1) % Q->MaxEl;
			Tail(*Q) = (Tail(*Q)-1);
			if (Tail(*Q)==-1){
				Tail(*Q) = Q->MaxEl-1; 
			} 
			while (i != tail)
			{
				idx  = (i+1) % Q->MaxEl;
				Elmt(*Q, i) = Elmt(*Q, idx);
				i=idx;
			}
		}
		else {
			// Tail
			Tail(*Q) = (Tail(*Q) - 1);
			if (Tail(*Q)==-1){
				Tail(*Q) = Q->MaxEl-1; 
			} 
		}
	}
}

/* Operasi Tambahan */
void PrintPrioQueue(PrioQueue Q)
{
	/* Mencetak isi queue Q ke layar */
	/* I.S. Q terdefinisi, mungkin kosong */
	/* F.S. Q tercetak ke layar dengan format: */

	// 	List Makanan di Inventory
	// (nama - waktu sisa kedaluwarsa)
	// <Nama Makanan 1> - <Waktu Makanan 1>
	// <Nama Makanan 2> - <Waktu Makanan 2>
	// <Nama Makanan 3> - <Waktu Makanan 3>
	// ...

	int i, no;
	no = 1;
	printf("List Makanan di Inventory\n");
	printf("(nama - waktu sisa kedaluwarsa)\n");
	if (!IsEmpty(Q))
	{
		i = Head(Q);
		while (i != Tail(Q))
		{
			if (i == MaxEl(Q))
			{
				i = 0;
			}
			if (i != Tail(Q))
			{
				printf("   %d. %s - ", no, NamaMakanan(Elmt(Q,i)));
				// printf("   %d. %s - %d ", no, NamaMakanan(Elmt(Q, i)), Elmt(Q, i).id); // buat method display 4 jam , 3 jam 10 menit, print sama getvar nya
				DisplayTIMEk(TimeFull((Q).T[i]));
				printf("\n");
				i++;
				no++;
			}
		}
		// printf("   %d. %s - %d ", no, NamaMakanan(Elmt(Q, i)), Elmt(Q, i).id); // buat method display 4 jam , 3 jam 10 menit, print sama getvar nya
		printf("   %d. %s - ", no, NamaMakanan(Elmt(Q,i)));
		DisplayTIMEk(TimeFull((Q).T[i]));
		printf("\n");
	}
}

void Min1Minute(PrioQueue *Q, boolean *Flag, ListMakanan *LMakanan)
{
	/* I.S. q terdefinisi */
	/* F.S. Semnua elemen makanan  dalam q berkurang 1 menit dan DequeueExp  */
	int i, nBefore;
	int nMknExp = 0;
	nBefore = LMakanan->NElmt;
	MAKANAN m;
	if (!IsEmpty(*Q))
	{
		i = Head(*Q);
		while (i != Tail(*Q))
		{
			if (i == MaxEl(*Q))
			{
				i = 0;
			}
			if (i != Tail(*Q))
			{
				PrevMin(&Exp(Elmt(*Q, i)));
				if (isThereExp(*Q))
				{
					DequeueExp(Q, &m);
					LMakanan->Lmakanan[LMakanan->NElmt] = m;
					LMakanan->NElmt++;
					*Flag = true;
				}
				i++;
			}
		}
		// Tail nya
		PrevMin(&Exp(Elmt(*Q, i)));
		if (isThereExp(*Q))
		{
			DequeueExp(Q, &m);
			LMakanan->Lmakanan[LMakanan->NElmt] = m;
			LMakanan->NElmt++;
			*Flag = true;
		}
		if (LMakanan->NElmt == nBefore)
		{
			Flag = false;
		}
	}
}

void MinNTime(PrioQueue *Q, boolean *Flag, ListMakanan *LMakanan, int h, int m){
	/* I.S. q terdefinisi */
	/* F.S. Semnua elemen makanan  dalam q berkurang h jam dan m menit dan DequeueExp  */
	int i, nBefore;
	int nMknExp = 0;
	TIME tim;
	long Nmin;
	CreateTime(&tim, 0, h, m);
	Nmin = TIMEToMin(tim);
	nBefore = LMakanan->NElmt;
	MAKANAN mkn;
	if (!IsEmpty(*Q))
	{
		i = Head(*Q);
		while (i != Tail(*Q))
		{
			if (i == MaxEl(*Q))
			{
				i = 0;
			}
			if (i != Tail(*Q))
			{
				PrevNMin(&Exp(Elmt(*Q, i)), Nmin);
				// PrevMin(&Exp(Elmt(*Q, i)));
				if (isThereExp(*Q))
				{
					DequeueExp(Q, &mkn);
					LMakanan->Lmakanan[LMakanan->NElmt] = mkn;
					LMakanan->NElmt++;
					*Flag = true;
				}
				i++;
			}
		}
		// Tail nya
		PrevNMin(&Exp(Elmt(*Q, i)), Nmin);
		// PrevMin(&Exp(Elmt(*Q, i)));
		if (isThereExp(*Q))
		{
			DequeueExp(Q, &mkn);
			LMakanan->Lmakanan[LMakanan->NElmt] = mkn;
			LMakanan->NElmt++;
			*Flag = true;
		}
		if (LMakanan->NElmt == nBefore)
		{
			Flag = false;
		}
	}
}
