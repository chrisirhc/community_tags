<?php
// $Id: community_tags.ajax.inc,v 1.2 2009/12/04 22:24:56 entrigan Exp $

/**
 * @file
 * community_tags.ajax.inc
 *
 * Handles the server side Ajax interactions of Community Tags.
 *
 * @defgroup community_tags_ajax Community Tags server side Ajax interactions.
 * @{
 */


/**
 * Callback for the JS tagger.
 */
function community_tags_from_js($node, $vid) {
  global $user;

  $tags = (isset($_POST['tags']) && is_array($_POST['tags'])) ? $_POST['tags'] : array();

  // Merge in new tag and save.
  $tags = array_unique(array_merge($tags, drupal_explode_tags($_POST['add'])));
  community_tags_taxonomy_node_save($node, array('tags' => array($vid => $tags)), FALSE, $user->uid);

  // Fetch updated list.
  $tags = community_tags_flatten(community_tags_get_user_node_tags($user->uid, $node->nid, $vid));

  // Output JSON.
  print drupal_json(array('status' => TRUE, 'tags' => $tags, 'sequence' => $_POST['sequence']));
}

/**
 * @}
 */
