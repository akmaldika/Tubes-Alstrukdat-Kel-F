/* File : prioqueue.c */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */

#include "PrioQueue.h"
#include <stdio.h>
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmptyPQ(PrioQueue Q)
{
	/* Mengirim true jika Q kosong: lihat definisi di atas */
	return Head(Q) == Nil && Tail(Q) == Nil;
}
boolean IsFullPQ(PrioQueue Q)
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
boolean isDelivDone(PrioQueue Q){
	/* Mengirim true jika dalam Q ada yang sudah selesai pengirimannya */
	return TimeAction(Elmt(Q, Head(Q))) < 1;
}
boolean searchMkn(PrioQueue Q, MAKANAN m)
{
	/* Mengirimkan true jika makanan terdapat dalam queue */
	if (IsEmptyPQ(Q))
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
	if (IsEmptyPQ(Q)) //
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
	if (Time(X) != 0)
	{
		if (IsFullPQ(*Q))
		{
			expandPQ(Q, MaxElPQ);
		}
		if (IsEmptyPQ(*Q))
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
	if (!IsEmptyPQ(*Q))
	{
		if(MaxEl(*Q) > MaxElPQ){
			if ((MaxEl(*Q) - NBElmt(*Q)) > MaxElPQ){
				shrinkPQ(Q, MaxElPQ/2);
			}
		}
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

void removeFromInventory(PrioQueue *Q, int ID){
	/* Proses: Menghapus makanan dengan id ID pada Q dengan aturan yang paling mendekati expired dimulai dari head 
	hingga menemukan m lalu dihapus */
	/* I.S. Q tidak mungkin kosong */
	/* F.S. makanan dengan id ID ter-dequeue (hapus) dari Q dan Q tetap teratur dengan mekanisme circular buffer
			Q mungkin menjadi kosong */
	if (! IsEmptyPQ(*Q))
	{
		MAKANAN temp;
		int idx;
		int tail;
		int i = Head(*Q);
		while (Elmt(*Q, i).id != ID)
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

void copyPQ(PrioQueue Qin, PrioQueue *Qout){
	/* Mengisi semua elemen Qout dengan elemen-elemen pada Qin */
	/* I.S. Qin terdefinisi dan Qout siap diisikan Qin */
	/* F.S. semua elemen Qin dicopy ke dalam Qout */
	int n = MaxEl(Qin);
	MakeEmpty(Qout, n);
	int i = Head(Qin);
	while (i != Tail(Qin) )
	{
		Enqueue(Qout, Elmt(Qin, i));
		i++;
		if(i == n){
			i=0;
		}
	}
	// Tail nya
	Enqueue(Qout, Elmt(Qin, i));
}

void expandPQ(PrioQueue *Q, int num){
	/* Memperbesar ukuran Q sebesar num */
	/* I.S. Q terdefinisi */
	/* F.S. Ukuran Q menjadi ukuran Q sebelumnya + num */
	PrioQueue temp;
	int c;
	int i;
	c = MaxEl(*Q);
	MakeEmpty(&temp, c);
	copyPQ(*Q, &temp);
	DeAlokasi(Q);

	// PQ yang baru
	MakeEmpty(Q, c + num);
	i = Head(temp);   
	while (i != Tail(temp))
	{
		/* code */
		Enqueue(Q, Elmt(temp, i));
		i++;
		if(i == c){
			i=0;
		}
	}
	Enqueue(Q, Elmt(temp, i));
}

void shrinkPQ(PrioQueue *Q, int num){
	/* Memperkecil ukuran Q sebesar num */
	/* I.S. Q terdefinisi */
	/* F.S. Ukuran Q menjadi ukuran Q sebelumnya - num */
	PrioQueue temp;
	int c;
	int i;
	c = MaxEl(*Q);
	MakeEmpty(&temp, c);
	copyPQ(*Q, &temp);
	DeAlokasi(Q);

	// PQ yang baru
	MakeEmpty(Q, c - num);
	i = Head(temp);   
	while (i != Tail(temp))
	{
		/* code */
		Enqueue(Q, Elmt(temp, i));
		i++;
		if(i == c){
			i=0;
		}
	}
	Enqueue(Q, Elmt(temp, i));

}

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
	if (!IsEmptyPQ(Q))
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

void PrintDelivery(PrioQueue Q)
{
	/* Mencetak isi queue Q ke layar */
	/* I.S. Q terdefinisi, mungkin kosong */
	/* F.S. Q tercetak ke layar dengan format: */

	// 	List Makanan di Perjalanan
	// (nama - waktu sisa delivery)
	// <Nama Makanan 1> - <Waktu Makanan 1>
	// <Nama Makanan 2> - <Waktu Makanan 2>
	// <Nama Makanan 3> - <Waktu Makanan 3>
	// ...

	int i, no;
	no = 1;
	printf("List Makanan di Perjalanan\n");
	printf("(nama - waktu sisa delivery)\n");
	if (!IsEmptyPQ(Q))
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
				DisplayTIMEk(((Q).T[i]).timeAction);
				printf("\n");
				i++;
				no++;
			}
		}
		// printf("   %d. %s - %d ", no, NamaMakanan(Elmt(Q, i)), Elmt(Q, i).id); // buat method display 4 jam , 3 jam 10 menit, print sama getvar nya
		printf("   %d. %s - ", no, NamaMakanan(Elmt(Q,i)));
		DisplayTIMEk(((Q).T[i]).timeAction);
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
	if (!IsEmptyPQ(*Q))
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
			*Flag = false;
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
	if (!IsEmptyPQ(*Q))
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
			*Flag = false;
		}
	}
}

void Min1MinuteDeliv(PrioQueue *Qdeliv, PrioQueue *Q, boolean *FlagExp, boolean *FlagDeliv, ListMakanan *LMakanan, ListMakanan *LdelivDone){  
	/* I.S. Qdeliv terdefinisi */
	/* F.S. Semnua elemen makanan  dalam Qdeliv berkurang 1 menit dan DequeueExp  */
	int i, nBefore;
	int nMknExp = 0;
	nBefore = LMakanan->NElmt;
	boolean exp = false, delivDone = false;
	MAKANAN m;
	if (!IsEmptyPQ(*Qdeliv))
	{
		i = Head(*Qdeliv);
		while (i != Tail(*Qdeliv))
		{
			if (i == MaxEl(*Qdeliv))
			{
				i = 0;
			}
			if (i != Tail(*Qdeliv))
			{
				PrevMin(&TimeAct(Elmt(*Qdeliv, i)));
				PrevMin(&Exp(Elmt(*Qdeliv, i)));
				// if(isThereExp(*Q)){
				// 	DequeueExp(Q, &m);
				// 	LMakanan->Lmakanan[LMakanan->NElmt] = m;
				// 	LMakanan->NElmt++;
				// 	*FlagExp = true;
				// 	exp = true;
				// }
				if (isThereExp(*Qdeliv))
				{
					DequeueExp(Qdeliv, &m);
					LMakanan->Lmakanan[LMakanan->NElmt] = m;
					LMakanan->NElmt++;
					*FlagExp = true;
					exp = true;
				}
				else if (isDelivDone(*Qdeliv)){
					// LdelivDone
					Dequeue(Qdeliv, &m);
					Enqueue(Q, m);
					LdelivDone->Lmakanan[LdelivDone->NElmt] = m;
					LdelivDone->NElmt++;
					*FlagDeliv=true;
					delivDone = true;
				}
				i++;
			}
		}
		// Tail nya
		PrevMin(&TimeAct(Elmt(*Qdeliv, i)));
		PrevMin(&Exp(Elmt(*Qdeliv, i)));
		// if(isThereExp(*Q)){
		// 	DequeueExp(Q, &m);
		// 	LMakanan->Lmakanan[LMakanan->NElmt] = m;
		// 	LMakanan->NElmt++;
		// 	*FlagExp = true;
		// 	exp = true;
		// }
		if (isThereExp(*Qdeliv))
		{
			DequeueExp(Qdeliv, &m);
			LMakanan->Lmakanan[LMakanan->NElmt] = m;
			LMakanan->NElmt++;
			*FlagExp = true;
			exp = true;
		}
		else if (isDelivDone(*Qdeliv)){
			// LdelivDone
			Dequeue(Qdeliv, &m);
			Enqueue(Q, m);
			LdelivDone->Lmakanan[LdelivDone->NElmt] = m;
			LdelivDone->NElmt++;
			*FlagDeliv=true;
			delivDone = true;
		}
		if (exp)
		{
			*FlagExp = false;
		}
		if(delivDone){
			*FlagDeliv = false;
		}
	}
}

void MinNTimeDeliv(PrioQueue *Qdeliv, PrioQueue *Q, boolean *Flag, boolean *FlagDeliv, ListMakanan *LMakanan, ListMakanan *LdelivDone, int h, int m){
	/* I.S. Qdeliv terdefinisi */
	/* F.S. Semnua elemen makanan  dalam Qdeliv berkurang h jam dan m menit dan DequeueExp  */
	int i, nBefore;
	int nMknExp = 0;
	nBefore = LMakanan->NElmt;
	boolean exp = false, delivDone = false;
	MAKANAN mkn;
	int min = h*60 + m; 
	if (!IsEmptyPQ(*Qdeliv))
	{
		i = Head(*Qdeliv);
		while (i != Tail(*Qdeliv))
		{
			if (i == MaxEl(*Qdeliv))
			{
				i = 0;
			}
			if (i != Tail(*Qdeliv))
			{
				PrevNMin(&TimeAct(Elmt(*Qdeliv, i)), min);
				PrevNMin(&Exp(Elmt(*Qdeliv, i)), min);
						// printf("m %d\n", TIMEToMin(Elmt(*Qdeliv, Head(*Qdeliv)).timeAction));
				if (TIMEToMin(Elmt(*Qdeliv, Head(*Qdeliv)).timeAction) < 1)
				{
					Dequeue(Qdeliv, &mkn);
					LMakanan->Lmakanan[LMakanan->NElmt] = mkn;
					LMakanan->NElmt++;
					*Flag = true;
					exp = true;
				}
				else if (isDelivDone(*Qdeliv)){
					// LdelivDone
					Dequeue(Qdeliv, &mkn);
					Enqueue(Q, mkn);
					LdelivDone->Lmakanan[LdelivDone->NElmt] = mkn;
					LdelivDone->NElmt++;
					*FlagDeliv=true;
					delivDone = true;
				}
				i++;
			}
		}
		// Tail nya
		PrevNMin(&TimeAct(Elmt(*Qdeliv, i)), min);
		PrevNMin(&Exp(Elmt(*Qdeliv, i)), min);
		if (TIMEToMin(Elmt(*Qdeliv, Head(*Qdeliv)).timeAction) <1)
		{
			Dequeue(Qdeliv, &mkn);
			LMakanan->Lmakanan[LMakanan->NElmt] = mkn;
			LMakanan->NElmt++;
			*Flag = true;
			exp = true;
		}
		else if (isDelivDone(*Qdeliv)){
			// LdelivDone
			Dequeue(Qdeliv, &mkn);
			Enqueue(Q, mkn);
			LdelivDone->Lmakanan[LdelivDone->NElmt] = mkn;
			LdelivDone->NElmt++;
			*FlagDeliv=true;
			delivDone = true;
		}
		if (exp)
		{
			*Flag = false;
		}
		if(delivDone){
			*FlagDeliv = false;
		}
	}

}

void DelivMakanan(PrioQueue *Qdeliv, MAKANAN m){
	/* I.S. Qdeliv terdefinisi */
	/* F.S. memasukan makanan m ke dalam Qdeliv */
	Enqueue(Qdeliv, m);
}

void waitCommand(PrioQueue *Qdeliv, PrioQueue *Q, boolean *FlagDeliv, boolean *FlagExp, ListMakanan *LMakanan, ListMakanan *LdelivDone,  int h, int m){
	/* I.S. Qdeliv terdefinisi */
	/* F.S. memasukan makanan m ke dalam Qdeliv */
	boolean cek = false;
	MinNTime(Q, FlagExp, LMakanan, h, m);
	if (FlagExp){
		cek = true;
	}
	if(! IsEmptyPQ(*Qdeliv)){
		MinNTimeDeliv(Qdeliv, Q, FlagExp, FlagDeliv, LMakanan, LdelivDone, h, m);
	}
	if (cek){
		*FlagExp = true;
	}
}

void min1menitAll(PrioQueue *Qdeliv, PrioQueue *Q, boolean *FlagDeliv, boolean *FlagExp, ListMakanan *LMakanan, ListMakanan *LdelivDone){
	/* I.S. Qdeliv dan Q (untuk inventory) terdefinisi */
	/* F.S. mengurangi 1 menit untuk semua makanan dalam inventory dan Qdeliv. Apabila sudah ada yang  selesai di delivery akan masuk ke dalam 
	inventory */
	boolean cek = false;
	Min1Minute(Q, FlagExp, LMakanan);
	if (FlagExp){
		cek = true;
	}
	if(! IsEmptyPQ(*Qdeliv)){
		Min1MinuteDeliv(Qdeliv, Q, FlagExp, FlagDeliv, LMakanan, LdelivDone);
	}
	if (cek){
		*FlagExp = true;
	}
}

void delAllPriqueue(PrioQueue *Qdeliv)
{
	/* I.S. Qdeliv dan QInven terdefinisi */
	/* F.S. menghapus semua elemen dari Qdeliv dan QInven */
	free(Qdeliv->T);
	Head(*Qdeliv) = Nil;
	Tail(*Qdeliv) = Nil;
	MaxEl(*Qdeliv) = 0;
}

boolean isPrioqueSame(PrioQueue q1, PrioQueue q2) {
	/* I.S. : q1 dan q2 terdefinisi */
	/* F.S.	: mengembalikan true jika q1 = q2 baik ukuran maupun setiap elemennya */

	boolean flag;
	int i, j;

	if (MaxEl(q1) != MaxEl(q2))
	{
		return false;
	}
	else
	{
		if (Head(q1) != Head(q2) || Tail(q1) != Tail(q2))
		{
			return false;
		}
		else
		{
			i = Head(q1);
			j = Head(q2);
			flag = true;
			while (flag && i <= Tail(q1) && j <= Tail(q2))
			{
				if (isMakananSame(Elmt(q1, i), Elmt(q2, j)))
				{
					if (i == MaxEl(q1))
					{
						i = 0;
					}
					else
					{
						i++;
					}

					if (j == MaxEl(q2))
					{
						j = 0;
					}
					else
					{
						j++;
					}
				}
				else
				{
					flag = false;
				}
			}

			return flag;
		}
	}
}
