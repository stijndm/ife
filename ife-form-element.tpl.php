<<<<<<< HEAD
<?php 
<<<<<<< HEAD
=======
// $Id$
>>>>>>> creating HEAD for IFE
=======
<?php
// $Id$

/**
 * @file
 *
 * Theme implementation to display a form element with it's error.
 *
 * Available variables:
 * - $field: the themed form element.
 * - $error_message: The error message(s). Multiple messages are themed as a list.
 * - $error: Returns TRUE if the form element has an error.
 * - $element: The raw element data (array).
 *
 * @see template_preprocess_ife_form_element()
 */
>>>>>>> Coder review fixes. Mostly removed trailing spaces.
?>

<?php print $field; ?>

<?php if ($error_message): ?>
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  <div class="messages error inline"><?php print $error_message; ?></div>
<<<<<<< HEAD
=======
  <div class='inline messages error'><?php print $error_message; ?></div>
>>>>>>> creating HEAD for IFE
=======
  <div class="messages error inline"><?php print $error_message; ?></div>
>>>>>>> Fix for invalid HTML
<?php endif; ?>
=======
<?php endif;
>>>>>>> Coder review fixes. Mostly removed trailing spaces.
=======
  <div class="messages error messages-inline"><?php print $error_message; ?></div>
<?php endif;
>>>>>>> Changed by swentel: Change default class names.
