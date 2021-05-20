from tools import *
import copy
#---------------------------------------------------------------------
# count : le compteur de numérotation
# il s'incrémente lors qu'il y a une nouvelle façon de numérotation
#---------------------------------------------------------------------
count = 0

#---------------------------------------------------------------------
# all_numeroter[] : tableau de numérotation
# Ce tableau contient toutes les numérotations possibles d'un graphe
# Ce tableau est utilisé pour éliminer les numérotations identiques
#---------------------------------------------------------------------
all_numeroter = []

#---------------------------------------------------------------------
# add_numeroter(tabS) : fonction qui ajoute une possibilité de numérotation
# dans le tableau all_numeroter
#---------------------------------------------------------------------
def add_numeroter(tabS):
    global all_numeroter
    _tabS = copy.copy(tabS)
    if _tabS not in all_numeroter:
        all_numeroter.append(_tabS)

#---------------------------------------------------------------------
# debut(tabA, n) : 
# tabA : tableau des aretes correspondant aux arêtes des sommets du graphe
# n : le nombre de sommets
# 
# on commence par numéroter un graphe avec r = 0 (r est le rang minimal
# avec une intervalle de 0 à n (n: le nombre de sommets dans le graphe))
# puis on fixe le 1er sommet avec la valeur de a=1 (de 1 à n+1)
# puis numéroter le reste des sommets avec la fonction successeur(r, 0, tabA, n)
#
# si count est différente à 0, càd une numérotation du graphe est bien fait
# mark devient à true
# on essaye alors une autre numérotation avec a+1 apres la mise à zero de tabS[] et de visit[]
# lorsqu'on a fini toutes les numérotation avec toutes les valeurs de a,
# on renvoie r
# 
# mais si la numérotaion du graphe avec r=0 et toutes les valeurs de a, c'est impossible
# on incrémente r, et on essaye ensuite avec r+1 et toutes les valeurs de a
# 
# s'il n'y a pas de numéroration possible pour un graphe, mark est alors toujours False
# on renvoie donc -1
#---------------------------------------------------------------------
def debut(tabA, n):
    global count
    mark = False
    for r in range(1, n):
        for a in range(1, n+1):
            tabS[0] = a
            visit[a] = True
            successeur(r, 0, tabA, n)
            if count > 0:
                mark = True
            clean_tabS(n) # met en zéro tabS[]
            clean_visit(n) # met en zéro visit[]
        if mark:
            return r
    return -1

#---------------------------------------------------------------------
# successeur(r, sommet, tabA, n) : fonction récurssive avec DFS
# r : le rang minimal définie dans la fonction debut(tabA,n)
# sommet : 0 au début, change avec i
# tabA : tableau des aretes correspondant aux arêtes des sommets du graphe
# n : le nombre de sommets
#
# on parcourt tabA[], s'il y a une arête entre les sommets avec indices 'sommet' et 'i'
# alors tabA[sommet][i] est à 1
#
# de plus, si tabS[i] est vide, une valeur 'value' qui est de 1 à n+1, n'est pas utilisée
# ainsi, si la capacité de l'arête entre les sommets avec indice 'sommet' et 'i'
# qui est plus petite ou égale à r
# alors on met la valeur de 'value' au (i+1)ième sommet avec l'indice de 'i'
# et on met visit[value] à False
#
# si tous les sommets sont numérotés, alors on incrémente 'count'
# ajoute une numérotation dans le tableau all_numeroter[] avec la fonction add_numeroter(tabS)
# puis inisialise tabS[i] et visit[value]
# puis return rien
# value est ensuite incrémenté, pour essayer avec une autre valeur de 'value' pour (i+1)ième sommet
# 
# si toutes les sommets ne sont pas encore touts numérotés
# on appele ensuite la fonction récursive successeur(r, i, tabA, n) refait la même manipulation
# et initialse tabS[i] et visit[value]
# 
# cette fonction est fait avec DFS, qui cherche d'abord toutes les valeurs possibles de dernier sommet
# puis revient à l'arrière
#
#---------------------------------------------------------------------
def successeur(r, sommet, tabA, n):
    global count
    for i in range(n):
        if (tabA[sommet][i] == 1) & (tabS[i] == 0):
            for value in range(1, n+1):
            	# vérifier l'utilisation de 'value'
            	# aussi la capacité de l'arrête est plus petit que r ou tabS[i] est vide
                if (visit[value] == False) & check_rang(r, i, value, tabA, n):
                    tabS[i] = value
                    visit[value] = True
                    # vérifier si touts les sommets sont numérotés
                    if check_all_visit(n):
                        count += 1
                        show_tabS(n)
                        # ajoute une numérotation réussite
                        add_numeroter(tabS)
                        tabS[i] = 0
                        visit[value] = False
                        return
                    successeur(r, i, tabA, n)
                    tabS[i] = 0
                    visit[value] = False


if __name__ == '__main__':

	# n : Nombre de sommets
    n = 5

	#---------------------------------------------------------------------
	# tabA : Tableau des aretes correspondant à l'arete entre les sommets
	# Par exemple, dans la 1ère ligne et la 2e colonne de tabA
	# c'est 1, c'est à dire que il y a une arete entre les sommets 1 et 2
	# Dans la 1ère ligne et la 3e colonne de tabA
	# c'est 1, il y a un arete entre les sommets 1 et 3, etc
	#---------------------------------------------------------------------
    # graphe aligné

    tabA = [
        [0,1,0,0,0],
        [1,0,1,0,0],
        [0,1,0,1,0],
        [0,0,1,0,1],
        [0,0,0,1,0]
    ]

	#tabA = [
    #	[0,1,1,0],
    #	[1,0,1,0],
    #	[1,1,0,1],
    #	[0,0,1,0]
   	#]
    
	#tabA = [
	#    [0,1,1,0,0,0,1,0],
	#    [1,0,0,1,0,0,0,1],
	#    [1,0,0,1,1,0,0,0],
	#    [0,1,1,0,0,1,0,0],
	#    [0,0,1,0,0,1,1,0],
	#    [0,0,0,1,1,0,0,1],
	#    [1,0,0,0,1,0,0,1],
	#    [0,1,0,0,0,1,1,0]
    #]
    init_tabS(n)
    init_visit(n)

    res = debut(tabA,n)
    print('\nle rang minimal est : {0}\n'.format(res))
    print('{0} numerotors'.format(count))

