<?php
// $Id: ife.theme.inc,v 1.1.2.1 2010/03/02 21:32:35 stijndm Exp $

/**
 * @file
 * Theme functions
 *
 * @author Stijn De Meyere
 */

/**
 * Theming function for the admin settings page
 */
function theme_ife_settings_form_ids($variables) {
  $form = $variables['form'];
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
    $row[] = l(t('Remove'), 'admin/config/ife/' . $key . '/delete');
    $rows[] = $row;
  }

  //new form_id
  $rows[] = array(
    drupal_render($form['new_form_id']['form_id']),
    drupal_render($form['new_form_id']['status']),
    drupal_render($form['new_form_id']['display']),
    drupal_render_children($form['new_form_id']['field_types']),
    '',
  );

  $output = theme('table', array('header' => $header, 'rows' => $rows));
  return $output;
}

/**
 * Theme the form element, add the error, when one occured.
 */
function theme_ife_form_element($variables) {

  $output = $variables['element']['#children'];
  if (isset($_SESSION['ife'][$variables['element']['#id']])) {
    $output .= '<div class="messages error messages-inline">' . $_SESSION['ife'][$variables['element']['#id']] . '</div>';
    unset($_SESSION['ife'][$variables['element']['#id']]);
  }

  return $output;

}