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

function feeds_tamper_email_form($importer, $element_key, $settings) {
  $form = array();
  // $form['email'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Set email to: '),
  //   '#default_value' => isset($settings['email']) ? $settings['email'] : 'noemail@duke.edu',
  //   '#description' => t('Email that will be given to account with blank email address.'),
  // );
  return $form;
}

// function feeds_tamper_email_validate(&$settings) {
//   $settings['email'] = trim($settings['email']);
// }

function feeds_tamper_email_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  if (empty($settings['email'])) {
    form_set_error('settings][email', t('No email set.'));
  }
  else {
    if(empty($field)) {
      $field = "noemail@duke.edu";
    }
    else {
      $field = $field;
    }
  }
  $field = $field;
}
