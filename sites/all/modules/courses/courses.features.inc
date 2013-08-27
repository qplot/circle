<?php
/**
 * @file
 * courses.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function courses_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_views_api().
 */
function courses_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function courses_node_info() {
  $items = array(
    'advisors' => array(
      'name' => t('Advisors'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Student ID'),
      'help' => '',
    ),
    'class' => array(
      'name' => t('Class'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'housing' => array(
      'name' => t('Housing'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Student ID'),
      'help' => '',
    ),
    'librarian' => array(
      'name' => t('Librarian'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Residence Hall'),
      'help' => '',
    ),
    'residence' => array(
      'name' => t('Residence'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Residence Hall'),
      'help' => '',
    ),
    'roster' => array(
      'name' => t('Roster'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
