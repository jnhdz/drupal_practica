<?php
/**
 * @file
 * Callbacks de administración del módulo saludar.
 */

/**
 * Define el formulario de opciones de configuración.
 */
function saludo_configuracion() {  
  $form['saludo_saludo'] = array(
    '#title' => 'Saludo que se muestra al usuario',  
    '#type' => 'textfield',
    '#default_value' => variable_get('saludo_saludo', 'primer modulo'),    
  );
  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => 'Guardar configuración',
  );
  $form['#submit'][] = 'saludo_configuracion_submit';  
  return $form;
}

/**
 * Valida el formulario de opciones de configuración.
 */
function saludo_configuracion_validate($form, &$form_state) {
  if (trim($form_state['values']['saludo_saludo']) == '') {
    form_set_error('saludo_saludo', 'El saludo no puede quedar vacío.');
  }
}

/**
 * Procesa el envío del formulario de opciones de configuración.
 */
function saludo_configuracion_submit($form, $form_state) {
  variable_set('saludo_saludo', $form_state['values']['saludo_saludo']);
  drupal_set_message("Se han guardado las opciones de configuración.");
}