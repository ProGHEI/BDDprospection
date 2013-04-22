<?php

function bddprospection_myform(){
$content = drupal_get_form('bddprospection_form');
return $content;
}

//CREATION DU FORMULAIRE AJOUTER UN APPEL
function bddprospection_form(){
  
 
  //Création de fieldset 
  
      // Cadre Entreprise autour des champs
       $form['selection_entreprise'] = array(

         '#type' => 'fieldset', 
         '#title' => t('ENTREPRISE EXISTANTE'), 
         '#weight' => 0, 
         '#collapsible' => TRUE, 
         '#collapsed' => FALSE,
         );
  
    // Cadre Entreprise autour des champs
    $form['entreprise'] = array(

      '#type' => 'fieldset', 
      '#title' => t('ENTREPRISE'), 
      '#weight' => 1, 
      '#collapsible' => TRUE, 
      '#collapsed' => FALSE,
      );

    //Cadre Contact autour des champs
    $form['contact'] = array(
      '#type' => 'fieldset', 
      '#title' => t('CONTACT'), 
      '#weight' => 2, 
      '#collapsible' => TRUE, 
      '#collapsed' => FALSE,
      );

    //Cadre Appel autour des champs
    $form['appel'] = array(
      '#type' => 'fieldset', 
      '#title' => t('APPEL'), 
      '#weight' => 3, 
      '#collapsible' => TRUE, 
      '#collapsed' => FALSE,
      );



//
//Création des différents champs de la page
//

  ////Création des champs Entreprise 
  
  //COMBOBOX
  $form['selection_entreprise_liste'] = array(
  '#title' => 'Sélectionner une entreprise',
  '#type' => 'select',
  '#options' => array(
         0 => 'test1',
         1 => 'test2',
         2 => 'test3',
         3 => 'test4',
         4 => 'test5',
         ),
  );  
    
////Création des champs Entreprise
  $form['entreprise_nom'] = array(
  '#title' => 'Nom de l\'entreprise',
  '#type' => 'textfield',
  '#required' => TRUE,
  );

  $form['entreprise_secteur'] = array(
  '#title' => 'Secteur d\'activité',
  '#type' => 'textfield',
  );

  $form['entreprise_adress'] = array(
  '#title' => 'Adresse',
  '#type' => 'textfield',
  );

  $form['entreprise_cp'] = array(
  '#title' => 'Code Postal',
  '#type' => 'textfield',
  );

  $form['entreprise_ville'] = array(
  '#title' => 'Ville',
  '#type' => 'textfield',
  );

  $form['entreprise_telephone'] = array(
  '#title' => 'Téléphone',
  '#type' => 'textfield',
  );

  $form['entreprise_fax'] = array(
  '#title' => 'Fax',
  '#type' => 'textfield',
  );

  $form['entreprise_mail'] = array(
  '#title' => 'E-mail',
  '#type' => 'textfield',
  );
 
  
  
  
////Création des champs Contact
  $form['contact_nom'] = array(
  '#title' => 'Nom',
  '#type' => 'textfield',
  );

  $form['contact_prenom'] = array(
  '#title' => 'Prénom',
  '#type' => 'textfield',
  );

  $form['contact_fonction'] = array(
  '#title' => 'Fonction',
  '#type' => 'textfield',
  );

  $form['contact_telephone'] = array(
  '#title' => 'Téléphone',
  '#type' => 'textfield',
  );

  $form['contact_portable'] = array(
  '#title' => 'Portable',
  '#type' => 'textfield',
  );

  $form['contact_mail'] = array(
  '#title' => 'E-mail',
  '#type' => 'textfield',
  );
  
    
  
  
  
  
 
  //Création d'un champ date
  //Attention la variable date_par_default est utilisée pour tous les champs dates de la page ;P
  $today = getdate();
  $today_formaté = '$today[year]'.'-'.'$today[mon]'.'-'.'$today[mday]';
  
  $format_date_appel = 'Y-m-d';
  $form['appel_date_appel'] = array(
     '#type' => 'date_select', // types 'date_text' and 'date_timezone' are also supported. See .inc file.
     '#title' => t('Sélectionner la date de l\'appel'),
     '#default_value' => $today_formaté, 
     '#date_format' => $format_date_appel,
     '#date_label_position' => 'within', // See other available attributes and what they do in date_api_elements.inc
     '#date_timezone' => 'Europe/Paris',
     '#date_year_range' => '0:+15',
  );
 
  //COMBOBOX
  $form['appel_appreciation'] = array(
  '#title' => 'Appréciation',
  '#type' => 'select',
  '#options' => array(
         0 => 'Pas de réponse',
         1 => 'Pas intéressée',
         2 => 'Intéressée',
         3 => 'Très intéressée',
         ),
  );

  //COMBOBOX
  $form['appel_rappel'] = array(
  '#title' => 'Relance',
  '#type' => 'select',
  '#options' => array(
         0 => 'Jamais',
         1 => 'Dans plus d\'un an',
         2 => 'D\'ici trois mois à un an',
         3 => 'Dans moins de trois mois',
         4 => 'Rapidement',
         ),
  );

  $form['appel_courriel_envoye'] = array(
  '#type' => 'checkbox',
  '#title' => t('Courriel envoyé'),
  );
  
  $form['appel_plaquette_envoye'] = array(
  '#type' => 'checkbox',
  '#title' => t('Plaquette envoyée'),
  );
  
  $form['appel_rendez_vous_obtenu'] = array(
  '#type' => 'checkbox',
  '#title' => t('Rendez-vous obtenu'),
  );
  
  //Création d'un champ date  
  $format_date_rdv = 'Y-m-d';
  $form['appel_date_rendez_vous'] = array(
     '#type' => 'date_select', // types 'date_text' and 'date_timezone' are also supported. See .inc file.
     '#title' => t('Date du rendez-vous'),
     '#default_value' => $today_formaté,
     '#date_format' => $format_date_rdv,
     '#date_label_position' => 'within', // See other available attributes and what they do in date_api_elements.inc
     '#date_timezone' => 'Europe/Paris',
     '#date_year_range' => '0:+15',
  );
  
   $form['appel_remarques'] = array(
   '#title' => 'Remarques Complémentaires',
   '#type' => 'textarea',
   );
  
  
  
   
  
  
//
//Attribution des champs créés à leur fieldset
//
   

////Attribution Fieldset Sélection_entreprise
    $form['selection_entreprise']['selection_entreprise_liste'] = $form['selection_entreprise_liste'];
    unset($form['selection_entreprise_liste']);
   
////Attributions Fieldset entreprise
    $form['entreprise']['entreprise_nom'] = $form['entreprise_nom'];
    unset($form['entreprise_nom']);

    $form['entreprise']['entreprise_secteur'] = $form['entreprise_secteur'];
    unset($form['entreprise_secteur']);

    $form['entreprise']['entreprise_adress'] = $form['entreprise_adress'];
    unset($form['entreprise_adress']);

    $form['entreprise']['entreprise_cp'] = $form['entreprise_cp'];
    unset($form['entreprise_cp']);

    $form['entreprise']['entreprise_ville'] = $form['entreprise_ville'];
    unset($form['entreprise_ville']);

    $form['entreprise']['entreprise_telephone'] = $form['entreprise_telephone'];
    unset($form['entreprise_telephone']);

    $form['entreprise']['entreprise_fax'] = $form['entreprise_fax'];
    unset($form['entreprise_fax']);

    $form['entreprise']['entreprise_mail'] = $form['entreprise_mail'];
    unset($form['entreprise_mail']);

    
    ////Attributions Fieldset contact
    $form['contact']['contact_nom'] = $form['contact_nom'];
    unset($form['contact_nom']);
    
    $form['contact']['contact_prenom'] = $form['contact_prenom'];
    unset($form['contact_prenom']);
    
    $form['contact']['contact_fonction'] = $form['contact_fonction'];
    unset($form['contact_fonction']);
    
    $form['contact']['contact_telephone'] = $form['contact_telephone'];
    unset($form['contact_telephone']);
    
    $form['contact']['contact_portable'] = $form['contact_portable'];
    unset($form['contact_portable']);
    
    $form['contact']['contact_mail'] = $form['contact_mail'];
    unset($form['contact_mail']);
        
    
    
    
    ////Attributions Fieldset appel
       
    $form['appel']['appel_date_appel'] = $form['appel_date_appel'];
    unset($form['appel_date_appel']);
    
    $form['appel']['appel_appreciation'] = $form['appel_appreciation'];
    unset($form['appel_appreciation']);
    
    $form['appel']['appel_rappel'] = $form['appel_rappel'];
    unset($form['appel_rappel']);
    
    $form['appel']['appel_courriel_envoye'] = $form['appel_courriel_envoye'];
    unset($form['appel_courriel_envoye']);
    
    $form['appel']['appel_plaquette_envoye'] = $form['appel_plaquette_envoye'];
    unset($form['appel_plaquette_envoye']);
    
    $form['appel']['appel_rendez_vous_obtenu'] = $form['appel_rendez_vous_obtenu'];
    unset($form['appel_rendez_vous_obtenu']);
    
    $form['appel']['appel_date_rendez_vous'] = $form['appel_date_rendez_vous'];
    unset($form['appel_date_rendez_vous']);
    
    $form['appel']['appel_remarques'] = $form['appel_remarques'];
    unset($form['appel_remarques']);
    


$form['valider'] = array(
'#type' => 'submit',
'#value' => t('Soumettre'),
'#weight' => 4,
);

return $form;
}







//
////FONCTION DE SOUMISSION DES DONNEES
//  

    //Action générées après avoir appuyé sur le bouton submit
    function bddprospection_form_submit($form, &$form_state){
    $query = db_insert('bddprospectionprog_entreprise');

    $query
    ->fields(array(
      'Nom'=>$form_state['values']['entreprise_nom'],
      'Secteur_activite'=>$form_state['values']['entreprise_secteur'],
      'Adresse'=>$form_state['values']['entreprise_adress'],
      'Code_Postal'=>$form_state['values']['entreprise_cp'],
      'Ville'=>$form_state['values']['entreprise_ville'],
      'Telephone'=>$form_state['values']['entreprise_telephone'],
      'Fax'=>$form_state['values']['entreprise_fax'],
      'Mail'=>$form_state['values']['entreprise_mail'],
      ))

    ->execute();
    }