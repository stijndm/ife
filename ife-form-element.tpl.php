<?php

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
?>

<?php print $field; ?>

<?php if ($error_message): ?>
  <div class="messages error messages-inline"><?php print $error_message; ?></div>
<?php endif;