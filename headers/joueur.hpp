/***********************************************************************************************************************
 * Classe "Joueur" qui gere les actions, les objets, et la position d'un joueur dans le jeu. La classe permet de creer
 * un joueur avec une salle de depart. Elle permet de changer la position du joueur vers une nouvelle salle et d'obtenir
 * la salle actuelle du joueur. La classe peut executer des actions basees sur des commandes, telles que se deplacer
 * vers une salle adjacente, afficher les informations de la salle actuelle ou des objets presents dans celle-ci, ou
 * utiliser des objets. Elle gere egalement les objets presents dans l'inventaire du joueur.
 *
 * @file joueur.hpp
 * @author Victor Paul-Hus-Cote et Wael El Karoui
 * @date 20 decembre 2024
 *
 * Cree le 25 novembre 2024
 **********************************************************************************************************************/

#pragma once

#include "objet.hpp"
#include "salle.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

class Joueur
{
public:
    /// @brief Classe "Joueur" qui gere les actions, les objets, et la position d'un joueur dans le jeu.
    /// @param salleDepart la salle de depart du joueur.
    Joueur(std::shared_ptr<Salle> salleDepart);

    /// @brief Deplace le joueur vers une nouvelle salle et affiche les informations de celle-ci et de l'inventaire.
    /// @param os le flot de sorties sur lequel afficher les informations.
    /// @param message le message a afficher apres le deplacement.
    /// @param salle la nouvelle salle du joueur.
    void deplacer(std::ostream& os, std::string message, std::shared_ptr<Salle> salle);

    /// @brief Execute une action basee sur une commande et des entrees.
    /// @param os le flot de sorties sur lequel afficher les informations.
    /// @param action la commande a executer.
    /// @param entrees les entrees supplementaires pour l'action.
    void faireAction(std::ostream& os, const std::string& action, const std::vector<std::string>& entrees);

    /// @brief Verifie si le joueur continue de jouer.
    /// @return vrai si le joueur continue de jouer.
    bool continueDeJouer() const { return continueDeJouer_; }
    std::shared_ptr<Salle> obtenirSalleActuelle() const { return salleActuelle_; }

private:
    /// @brief Affiche les objets presents dans l'inventaire du joueur.
    /// @param os le flot de sorties sur lequel afficher les informations.
    void afficherInventaire_(std::ostream& os) const;

    /// @brief Execute la commande "infos" pour afficher les informations d'un objet.
    /// @param os le flot de sorties sur lequel afficher les informations.
    /// @param entrees l'objet a afficher les informations, ou vide pour afficher les informations de la salle.
    void commandeInfos_(std::ostream& os, const std::vector<std::string>& entrees);

    /// @brief Execute la commande "prendre" pour prendre un objet dans la salle.
    /// @param os le flot de sorties sur lequel afficher les informations.
    /// @param entrees l'objet dans la salle a prendre (ne doit pas etre vide).
    void commandePrendre_(std::ostream& os, const std::vector<std::string>& entrees);

    /// @brief Execute la commande "utiliser" pour utiliser un objet dans la salle ou dans l'inventaire.
    /// @param os le flot de sorties sur lequel afficher les informations.
    /// @param entrees l'objet a utiliser (ne doit pas etre vide).
    void commandeUtiliser_(std::ostream& os, const std::vector<std::string>& entrees);

    /// @brief Trouve un objet dans l'inventaire ou dans la salle a partir d'une liste d'entrees.
    /// @param entrees la liste d'entrees a analyser.
    /// @return le nom de l'objet trouve.
    std::string trouverObjet_(const std::vector<std::string>& entrees) const;

    bool continueDeJouer_ = true;
    std::shared_ptr<Salle> salleActuelle_;
    std::map<std::string, std::unique_ptr<Objet>> objets_;
    std::map<std::string, std::function<void(std::ostream&, const std::vector<std::string>&)>> commandes_;
};