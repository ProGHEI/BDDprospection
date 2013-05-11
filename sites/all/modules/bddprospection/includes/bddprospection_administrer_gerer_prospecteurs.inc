function bddprospection_gerer_prospecteurs() {

  # configure the table header columns
  $header = array(
    array('data' => 'Matricule',        'field' => 'Matricule_HEI',               'sort' => 'ASC'),
    array('data' => 'Nom',              'field' => 'Nom',                         'sort' => 'ASC'),
    array('data' => 'Prenom',           'field' => 'Prenom',                      'sort' => 'ASC'),
    array('data' => 'Mandat',           'field' => 'Mandat',                      'sort' => 'ASC'),
    array('data' => 'Classe',           'field' => 'Classe',                      'sort' => 'ASC'),
    array('data' => 'Telephone',        'field' => 'Telephone',                   'sort' => 'ASC'),
    array('data' => 'Departement',      'field' => 'Departement',                 'sort' => 'ASC'),
    array('data' => 'Responsable',      'field' => 'Directeur_de_departement',    'sort' => 'ASC'),
 
  );

  # set the database table and initial SelectQuery options
  # $select is a SelectQuery object.
  # @see http://api.drupal.org/api/drupal/includes--database--select.inc/class/Se...
  $select = db_select('bddprospectionprog_prospecteurs','p')
              ->extend('PagerDefault')
              ->extend('TableSort');

  # get the desired fields
  # orderByHeader is a TableSort method (http://api.drupal.org/api/drupal/includes--tablesort.inc/function/TableS...)
  $select->fields('p', array('Matricule_HEI', 'Nom', 'Prenom', 'Mandat', 'Classe','Telephone','Departement','Directeur_de_departement'))
         ->limit(20)
         ->orderByHeader($header)
         ->orderBy('Matricule_HEI', 'DESC');  # TODO this call seems to be losing to orderByHeader on page load

  # execute the query
  $results = $select->execute();

  # configure the table rows, making the first column a link to our 'edit' page
  $rows = array();
  foreach ($results as $row) {
    $rows[] = array("<a href=\"/projects/edit/" . $row->Matricule_HEI . "\">" . $row->Matricule_HEI . '</a>',
                    $row->Nom,
                    $row->Prenom,
                    $row->Mandat,
                    $row->Classe,
                    $row->Telephone,
                    $row->Departement,
                    $row->Directeur_de_departement,
    );
  }

  $output = theme('table', array('header' => $header,
                                 'rows' => $rows ));

  # add the pager
  $output .= theme('pager');

  return $output;

}