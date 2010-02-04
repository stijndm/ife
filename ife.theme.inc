<?php
// $Id$

/**
 * @file
 * Theme functions
 *
 * @author Stijn De Meyere
 */

/**
 * Theming function for the admin settings page
 */
function theme_ife_settings_form_ids($form) {
  $header = array('form_id', t('Status'), t('Display type'), t('Field types'), t('Operations'));
  $rows = array();
  
  $keys = element_children($form);
  array_pop($keys);
  
  //existing form_ids
  foreach ($keys as $key) {
    $row = array();
    $row[] = drupal_render($form[$key]['form_id']);
    $row[] = drupal_render($form[$key]['status']);
    $row[] = drupal_render($form[$key]['display']);
    $row[] = drupal_render($form[$key]['field_types']);
    $row[] = l(t('Remove'), 'admin/settings/ife/'. $key .'/delete');
    $rows[] = $row;
  }
  
  //new form_id
  $rows[] = array(
    drupal_render($form['new_form_id']['form_id']), 
    drupal_render($form['new_form_id']['status']), 
    drupal_render($form['new_form_id']['display']),
    drupal_render($form['new_form_id']['field_types']), 
    '');
 
  $output = theme('table', $header, $rows); 
  return $output;
}


/**
 * Form element preprocess theming function
 */
function template_preprocess_ife_form_element(&$vars) {
  //reset field type 
  $vars['element']['#type'] = $vars['element']['#field_type'];
  unset($vars['element']['#field_type']);
  
  $element = $vars['element'];
  
  //theme the field
  $vars['field'] = theme($vars['element']['#type'], $element);
  
  //check for errors and settings
  if ($error_message = form_get_error($element)) {
    //get error id
    $error_id = array_search($error_message, $_SESSION['messages']['error']);
    
    if ($error_id !== FALSE) {
      if ($element['#display_type'] != 0) { 
        unset($_SESSION['messages']['error'][$error_id]);
        $_SESSION['messages']['error'] = array_values($_SESSION['messages']['error']);
      }
      
      if (count($_SESSION['messages']['error']) <= 0) {
        unset($_SESSION['messages']['error']);
      }
      
      //set error to TRUE and set error message
      $vars['error_message'] = $error_message;
      $vars['error'] = TRUE;      
    }
  }
  
}