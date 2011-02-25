<?php

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
  $element = $vars['element'];

  //theme the field
  //some strange things happening here with expandables vs singles
  if (in_array($vars['element']['#field_type'], ife_expandable_field_types())) {
    $vars['field'] = drupal_render($element);
  }
  else {
    $vars['field'] = theme($element['#field_type'], $element);
  }
  
  $errors = array();
  
  //get main ellement error
  $element_error = ife_element_get_error($element);
  if (trim($element_error)) {
    $errors[] = $element_error;
  }
  
  //cck type support
  if ($element['value']) {
    $values = element_children($element['value']);
    
    //get main field error
    $element['value']['#display_type'] = $element['#display_type'];
    $element_error = ife_element_get_error($element['value']);
    if (trim($element_error)) {
      $errors[] = $element_error;
    }
    
    //get sub errors
    if (count($values)) {
      foreach($values as $key)  {
        //pass along display_type
        $element['value'][$key]['#display_type'] = $element['#display_type'];
        //get errors
        $element_error = ife_element_get_error($element['value'][$key]);
        if (trim($element_error)) {
          $errors[] = $element_error;
        }
      }
    }
  }

  if (count($errors)) {
    if (count($errors) > 1) {
      $vars['error_message'] = theme('item_list', $errors);
    }
    else {
      $vars['error_message'] = $errors[0];
    }
  
    $vars['error'] = TRUE; 
  }
}