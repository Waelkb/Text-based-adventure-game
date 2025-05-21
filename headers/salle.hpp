/***********************************************************************************************************************
 * Classe "Salle" qui gere ses salles adjacentes dans le monde du jeu. La classe permet de creer une salle avec un nom
 * et une description. Elle permet d'afficher les informations de la salle, incluant son nom, sa description et la liste
 * des salles adjacentes. Elle permet aussi d'ajouter des salles adjacentes en specifiant une direction et une lettre de
 * direction, et d'ajouter des objets en transferant la propriete de leur pointeur. Elle permet aussi de verifier si un
 * deplacement vers une direction donnee est valide et d'obtenir la direction associee a un deplacement.
 *
 * @file salle.hpp
 * @author Victor Paul-Hus-Cote et Wael El Karoui
 * @date 20 decembre 2024
 *
 * Cree le 25 novembre 2024
 **********************************************************************************************************************/

#pragma once

#include "objet.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

class Salle
{
public:
    /// @brief Classe "Salle" qui gere ses salles adjacentes dans le monde du jeu.
    /// @param nom le nom de la salle.
    /// @param description une courte description des lieux.
    Salle(std::string nom, std::string description) : nom_(nom), description_(description) {}

    /// @brief Affiche les informations de la salle.
    /// @param os le flot de sorties sur lequel afficher les informations.
    /// @param style le caractere utilise pour la decoration de la ligne.
    /// @param largeur la largeur de la ligne avec le nom de la salle.
    void afficherInfos(std::ostream& os, char style = '~', int largeur = 26) const;

    /// @brief Ajoute une salle adjacente a la salle courante.
    /// @param salle la salle adjacente a ajouter.
    /// @param motCle un mot cle unique pour selectionner la salle adjacente.
    void ajouterSalleAdjacente(std::shared_ptr<Salle> salle, std::string motCle);

    /// @brief Ajoute un objet a la salle.
    /// @param objet le pointeur unique de l'objet a ajouter.
    void ajouterObjet(std::unique_ptr<Objet> objet) { objets_[objet->obtenirNom()] = std::move(objet); }

    /// @brief Verifie si un deplacement vers une direction donnee est valide.
    /// @param motCle le mot cle du deplacement.
    /// @return vrai si une salle adjacente existe avec le mot cle donne.
    bool estUnDeplacementValide(const std::string& motCle) const;

    /// @brief Verifie si la salle contient un objet.
    /// @param nomObjet le nom de l'objet a verifier.
    /// @return vrai si l'objet est present dans la salle.
    bool contientObjet(const std::string& nomObjet) const { return objets_.find(nomObjet) != objets_.end(); }

    /// @brief Obtiens le nom de la salle.
    /// @return le nom de la salle.
    std::string obtenirNom() const { return nom_; }

    /// @brief Obtiens la liste des directions possibles.
    /// @return la liste des directions.
    static const std::map<std::string, std::string> obtenirDirections() { return directions_; }

    /// @brief Obtiens les directions possibles que le joueur peut prendre a partir de la salle.
    /// @return la liste des directions possibles.
    std::vector<std::string> obtenirDirectionsPossible() const;

    /// @brief Obtiens la salle adjacente associee a un deplacement.
    /// @param motCle le mot cle du deplacement.
    /// @return la salle adjacente associee au deplacement.
    std::shared_ptr<Salle> obtenirSalleAdjacente(const std::string& motCle) const;

    /// @brief Obtiens le nom des objets presents dans la salle.
    /// @return la liste des noms des objets.
    std::vector<std::string> obtenirNomsObjets() const;

    /// @brief Obtiens une reference constante a un objet present dans la salle.
    /// @param nomObjet le nom de l'objet a obtenir.
    /// @return une reference constante a l'objet.
    const std::unique_ptr<Objet>& obtenirObjet(const std::string& nomObjet) const;

    /// @brief Permet au joueur de prendre un objet de la salle (il est consequemment retire de la salle).
    /// @param nomObjet le nom de l'objet a prendre.
    /// @return le pointeur unique de l'objet pris.
    std::unique_ptr<Objet> prendreObjet(const std::string& nomObjet);

private:
    std::string nom_;
    std::string description_;
    std::map<std::string, std::weak_ptr<Salle>> sallesAdjacentes_;
    std::map<std::string, std::unique_ptr<Objet>> objets_;

    inline static const std::map<std::string, std::string> directions_ = {
        {"n", "au Nord"}, {"s", "au Sud"}, {"e", "a l'Est"}, {"o", "a l'Ouest"}};
};