#include <stdio.h>
#include <string.h>

struct date
{
        int j, m, a;
};

struct etud
{
        long code;
        char nom[20];
        char pre[20];
        struct date d;
        float tn[10];
        float moy;
};

int test(struct etud te[], int ne, int pos, long c)
{
        for (int i = 0; i < pos; i++)
        {
                if (c == te[i].code)
                {
                        return 1;
                }
        }
        return 0;
}

void saisie(struct etud te[], int ne, int nn)
{
        for (int i = 0; i < ne; i++)
        {
                do
                {
                        printf("Code: ");
                        scanf("%ld", &te[i].code);
                } while (test(te, ne, i, te[i].code));

                printf("Nom: ");
                scanf("%s", te[i].nom);

                printf("Prenom: ");
                scanf("%s", te[i].pre);

                printf("Date (jj mm aaaa): ");
                scanf("%d %d %d", &te[i].d.j, &te[i].d.m, &te[i].d.a);

                for (int j = 0; j < nn; j++)
                {
                        printf("Note %d: ", j + 1);
                        scanf("%f", &te[i].tn[j]);
                }
        }
}

void coef(float tc[], int nn)
{
        for (int i = 0; i < nn; i++)
        {
                printf("Coef %d: ", i + 1);
                scanf("%f", &tc[i]);
        }
}

void cal_moy(struct etud te[], int ne, float tc[], int nn)
{
        for (int i = 0; i < ne; i++)
        {
                float s = 0, coeff = 0;
                for (int j = 0; j < nn; j++)
                {
                        s += tc[j] * te[i].tn[j];
                        coeff += tc[j];
                }
                te[i].moy = s / coeff;
        }
}

float moy_cla(struct etud te[], int ne)
{
        float s = 0;
        for (int i = 0; i < ne; i++)
        {
                s += te[i].moy;
        }
        return s / ne;
}

void trier(struct etud te[], int ne)
{
        for (int i = 0; i < ne - 1; i++)
        {
                for (int j = i + 1; j < ne; j++)
                {
                        if (strcmp(te[i].nom, te[j].nom) > 0)
                        {
                                struct etud temp = te[i];
                                te[i] = te[j];
                                te[j] = temp;
                        }
                }
        }
}

int rang(struct etud te[], int ne, long code)
{
        for (int i = 0; i < ne; i++)
        {
                if (te[i].code == code)
                {
                        return i + 1;
                }
        }
        return -1;
}

int main()
{
        int ne, nn;
        printf("n-etudiants: ");
        scanf("%d", &ne);

        printf("n-notes: ");
        scanf("%d", &nn);

        struct etud te[ne];
        float tc[nn];

        saisie(te, ne, nn);
        coef(tc, nn);
        cal_moy(te, ne, tc, nn);

        printf("Moy de classe: %.2f\n", moy_cla(te, ne));

        trier(te, ne);
        printf("\nEtudiants trie par nom:\n");

        for (int i = 0; i < ne; i++)
        {
                printf("%s %s(%d/%d/%d) : Moyenne = %.2f / Rang : %d\n", te[i].nom, te[i].pre,te[i].d.j,te[i].d.m,te[i].d.a, te[i].moy,rang(te, ne, te[i].code));
        }

        return 0;
}
