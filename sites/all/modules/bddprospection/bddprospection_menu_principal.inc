<?php


function bddprospection_form_menu_principal(){
$content = drupal_get_form('bddprospection_menu_principal_form');
return $content;
}


function bddprospection_menu_principal_form() {

$form['bouton_ajouter_un_appel'] = array(
    '#type' => 'submit',
    '#value' => t('Ajouter un appel'),
    '#submit' => array('bddprospection/formulaire'),
  );

$form['bouton_ajouter_un_appel'] = array(
    '#type' => 'submit',
    '#value' => t('Ajouter un appel'),
    '#submit' => array('bddprospection/formulaire'),
  );

$form['bouton_ajouter_un_appel'] = array(
    '#type' => 'submit',
    '#value' => t('Ajouter un appel'),
    '#submit' => array('bddprospection/formulaire'),
  );

$form['bouton_ajouter_un_appel'] = array(
    '#type' => 'submit',
    '#value' => t('Ajouter un appel'),
    '#submit' => array('bddprospection/formulaire'),
  );

$form['bouton_ajouter_un_appel'] = array(
    '#type' => 'submit',
    '#value' => t('Ajouter un appel'),
    '#submit' => array('bddprospection/formulaire'),
  );


  return $form;  
}