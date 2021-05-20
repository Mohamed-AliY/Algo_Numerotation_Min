#---------------------------------------------------------------------
# tabS[n] : tableau de sommets 
# le 1er élément du tabS indique la numérotation du 1er sommet
#---------------------------------------------------------------------
tabS = []

#---------------------------------------------------------------------
# visit[n+1] : tableau de visit
# le 1er élément de ce tableau n'est jamais utilisé
# les éléments suivants correspondent à l'utilisation de chiffres
# Par exemple, le 2e élément de ce tableau avec une indice 1
# c'est donc le chiffre 1
# s'il y a 'false' à cette position, cela signifie que le chiffre 1 n'est pas encore utilisé
# si 'true' dans cette position, cela signifie que le chiffre 1 est utilisé
#---------------------------------------------------------------------
visit = []

#---------------------------------------------------------------------
# init_tabS(n) :
# créer le tabS[] avec la taille 'n' et la valeur '0'
#---------------------------------------------------------------------
def init_tabS(n):
    for i in range(n):
        tabS.append(0)

#---------------------------------------------------------------------
# init_visit(n) :
# créer visit[] avec la taille 'n' et la valeur 'False'
#---------------------------------------------------------------------
def init_visit(n):
    for i in range(n+1):
        visit.append(False)

#---------------------------------------------------------------------
# show_tabS(n) :
# affiche le tabS[] donc la numérotation
#---------------------------------------------------------------------
def show_tabS(n):
    for i in range(n):
        print(tabS[i], end = " ")
    print("\n--------")

#---------------------------------------------------------------------
# clean_tabS(n) :
# initialise le tabS[] avec la valeur '0'
#---------------------------------------------------------------------
def clean_tabS(n):
    for i in range(n):
        tabS[i] = 0

#---------------------------------------------------------------------
# clean_visit(n) :
# initialise le visit[] avec la valeur 'False'
#---------------------------------------------------------------------
def clean_visit(n):
    for i in range(n+1):
        visit[i] = False

#---------------------------------------------------------------------
# check_all_visit(n) :
# vérifier la valeur des éléments de tabS[]
# si l'un des éléments est à 0, cela signifie qu' il n'est pas numéroté
# alors la numérotation n'est pas encore finie, renvoie False
#
# si tous les éléments ne sont pas à 0, renvoie True
#---------------------------------------------------------------------
def check_all_visit(n):
    for i in range(n):
        if tabS[i] == 0:
            return False
    return True

#---------------------------------------------------------------------
# check_rang(r, sommet, value, tabA, n) :
# vérifie s'il y a un arête entre les sommets avec indice 'sommet' et 'n'
# ainsi si l'écart entre ces sommets(on dit que c'est la capacité de l'arête)
# qui est plus grand que r(le rang minimal)
# et si le (i)ième sommet n'est pas vide (tabS[i] == 0)
# alors on renvoie False
#
# si tout les sommets sont vérifiés, on renvoie True 
#---------------------------------------------------------------------
def check_rang(r, sommet, value, tabA, n):
    for i in range(n):
        if tabA[sommet][i] == 1:
            if (abs(value-tabS[i]) <= r) | (tabS[i] == 0):
                continue
            else:
                return False
    return True