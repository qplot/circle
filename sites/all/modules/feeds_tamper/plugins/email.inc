<?php

/**
 * @file
 * Pad a string to a certain length with another string.
 */

$plugin = array(
  'form' => 'feeds_tamper_email_form',
  'callback' => 'feeds_tamper_email_callback',
  // 'validate' => 'feeds_tamper_email_validate',
  'name' => 'Email',
  'category' => 'Other',
);

// function feeds_tamper_email_validate(&$settings) {
//   $settings['email'] = trim($settings['email']);
// }

function feeds_tamper_email_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  if(empty($field)) {
    $field = "noemail@duke.edu";
  }
  else {
    $field = $field;
  }
  $field = $field;
}
