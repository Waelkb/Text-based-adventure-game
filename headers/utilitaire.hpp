/***********************************************************************************************************************
 * Programme utilitaire pour le jeu d'aventure textuelle. Ce fichier contient des fonctions pour initialiser les salles
 * et les objets, nettoyer le terminal, afficher une banniere et gerer les actions du joueur. Ce sont des fonctions qui
 * auraient pu se retrouver dans le fichier "main", mais elles ont ete deplacees ici pour liberer de la place et rendre
 * le fichier principal plus simple a comprendre.
 *
 * @file utilitaire.hpp
 * @author Victor Paul-Hus-Cote et Wael El Karoui
 * @date 20 decembre 2024
 *
 * Cree le 25 novembre 2024
 **********************************************************************************************************************/

#pragma once

#include "joueur.hpp"
#include "objet.hpp"
#include "salle.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

/// @brief Cree et initialise les salles du jeu, ainsi que les liens entre elles.
/// @return un vecteur contenant les salles du jeu.
std::vector<std::shared_ptr<Salle>> initialiserSalles();

/// @brief Cree et initialise les objets dans les salles du jeu, ainsi que leurs utilites.
/// @param os le flot de sorties pour afficher les informations.
/// @param salles le vecteur contenant les salles du jeu.
void initialiserObjets(std::ostream& os, std::vector<std::shared_ptr<Salle>>& salles);

/// @brief Nettoie le terminal avec des "escape codes".
/// @param os le flot de sorties ou envoyer les codes de nettoyage.
void nettoyageTerminal(std::ostream& os);

/// @brief Envoie sur le flot de sorties une banniere emboitant le nom du projet et un titre separer par une ligne.
/// @param os le flot de sorties sur lequel afficher la banniere.
/// @param titre le titre de la banniere.
/// @param espaces la taille du "padding" horizontale a ajouter a la boite, en nombre d'espaces.
void affichageBanniere(std::ostream& os, const std::string& titre, int espaces = 1);

/// @brief Affiche un caractere d'invite avant de lire l'action du joueur.
/// @param os le flot de sorties pour afficher l'invite
/// @param is le flot d'entrees pour lire l'action du joueur
/// @param joueur le joueur qui doit effectuer l'action
void prendreActionJoueur(std::ostream& os, std::istream& is, const std::shared_ptr<Joueur>& joueur);

/// @brief Trouve l'index d'une salle dans un vecteur a partir de son nom.
/// @param salles le vecteur contenant les salles du jeu.
/// @param nomSalle le nom de la salle a trouver.
/// @return l'index de la salle dans le vecteur, ou std::numeric_limits<size_t>::max() si la salle n'est pas trouvee.
static size_t obtenirIndexParNom(std::vector<std::shared_ptr<Salle>>& salles, std::string nomSalle);