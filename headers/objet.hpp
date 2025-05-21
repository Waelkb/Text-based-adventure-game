/***********************************************************************************************************************
 * Classe "Objet" qui gere la presence d'objets dans les salles du jeu. Les objets ont un nom, une description et ont la
 * possibilite d'etre obtenus par le joueur. Ils peuvent aussi avoir une utilite dans une salle specifique. Si l'objet a
 * une utilite, une fonction lambda est associee a l'objet pour effectuer une action specifique.
 *
 * @file objet.hpp
 * @author Victor Paul-Hus-Cote et Wael El Karoui
 * @date 20 decembre 2024
 *
 * Cree le 14 decembre 2024
 **********************************************************************************************************************/

#pragma once

#include <functional>
#include <string>

class Joueur;

class Objet
{
public:
    /// @brief Classe "Objet" qui gere les objets dans les salles du jeu.
    /// @param nom le nom de l'objet.
    /// @param description une courte description de l'objet.
    /// @param estObtenable vrai si l'objet peut etre obtenu par le joueur.
    Objet(std::string nom, std::string description, bool estObtenable = false);

    /// @brief Associe une utilite (une fonction) a l'objet pour une salle specifique.
    /// @param nomSalleUtile le nom de la salle ou l'objet a une utilite ("all" pour toutes les salles).
    /// @param utilite la fonction a executer si l'objet est utilise dans la salle specifiee.
    void ajouterUtilite(std::string nomSalleUtile, std::function<void(Joueur&)> utilite);

    /// @brief Obtiens le nom de l'objet.
    /// @return le nom de l'objet.
    std::string obtenirNom() const { return nom_; }

    /// @brief Obtiens la description de l'objet.
    /// @return la description de l'objet.
    std::string obtenirDescription() const { return description_; }

    /// @brief Obtiens le nom de la salle ou l'objet a une utilite.
    /// @return le nom de la salle ou l'objet a une utilite.
    std::string obtenirNomSalleUtile() const { return nomSalleUtile_; }

    /// @brief Verifie si l'objet est obtenable.
    /// @return vrai si l'objet est obtenable.
    bool estObtenable() const { return estObtenable_; }

    /// @brief Verifie si l'objet a une utilite quelconque.
    /// @return vrai si l'objet a une utilite.
    bool estUtile() const { return estUtile_; }

    /// @brief Utilise l'objet pour effectuer une action dans une salle.
    /// @param joueur le joueur qui utilise l'objet.
    void utiliser(Joueur& joueur) const { utilite_(joueur); }

private:
    std::string nom_;
    std::string description_;
    bool estObtenable_;

    bool estUtile_ = false;
    std::string nomSalleUtile_;
    std::function<void(Joueur&)> utilite_;
};