<?php
function community_tags_views_data()
{
  $data = array (
    'community_tags'=> array (
      'table'=> array (
        'group'=>t('Community Tags'),
        'base'=> array (
          'field'=>'tid',
          'title'=>t('Community Tags Entries'),
          'help'=>t("Records of who tagged what when (for Community Tag vocabularies)"),
          ),
        'join'=> array (
          'node'=> array (
            'left_field'=>'nid',
            'field'=>'nid',
            ),
          ),
        ),

      'uid'=> array (
        'title'=>t('Tagging User'),
        'help'=>t('The UID of the user who created the tag instance'),
        'field'=> array (
          'handler'=>'views_handler_field_user',
          'click sortable'=>TRUE,
          ),
        'argument'=> array (
          'handler'=>'views_handler_argument_user_uid',
          'name field'=>'name',
          ),
        'filter'=> array (
          'title'=>t('Name'),
          'handler'=>'views_handler_filter_user_name',
           ),
        'sort'=> array (
          'handler'=>'views_handler_sort',
          ),
        'relationship'=> array (
          'base'=>'users',
          'base field'=>'uid',
          'relationship field'=>'uid',
          'label'=>t('Community Taxonomy Tagging User'),
          ),
        ),

      'date'=> array (
        'title'=>t('Tagging Time'),
        'help'=>t('When the tag instance happened'),
        'field'=> array (
          'handler'=>'views_handler_field_date',
          'click sortable'=>TRUE,
          ),
        'sort'=> array (
          'handler'=>'views_handler_sort_date',
          ),
        'filter'=> array (
          'handler'=>'views_handler_filter_date',
          ),
        'argument'=> array (
          'handler'=>'views_handler_argument_date',
           ),
        ),

       'nid'=> array (
        'title'=>t('Tagged Node'),
        'help'=>t('The node that was tagged'),
        'field'=> array (
          'handler'=>'views_handler_field_numeric',
          'click sortable'=>TRUE,
          ),
        'sort'=> array (
          'handler'=>'views_handler_sort_numeric',
          ),
        'filter'=> array (
          'handler'=>'views_handler_filter_numeric',
          ),
        'argument'=> array (
          'handler'=>'views_handler_argument_numeric',
          ),
        ),

      'tid'=> array (
        'title'=>t('Tag ID'),
        'help'=>t('The TID of the Tag'),
         'relationship'=> array (
          'base'=>'term_data',
          'base field'=>'tid',
          'relationship field'=>'tid',
          'label'=>t('user flagged content'),
          ),
        'field'=> array (
          'handler'=>'views_handler_field_numeric',
          'click sortable'=>TRUE,
          ),
        'sort'=> array (
          'handler'=>'views_handler_sort_numeric',
          ),
        'filter'=> array (
          'handler'=>'views_handler_filter_numeric',
          ),
        'argument'=> array (
          'handler'=>'views_handler_argument_numeric',
          'skip base'=> array ('node', 'node_revision'),
          ),
        'relationship'=> array (
          'base'=>'term_data',
          'base field'=>'tid',
          'relationship field'=>'tid',
          'label'=>t('Community Taxonomy Tagged Term'),
          ),
        ),

      ),
  );

  return $data;
}

function community_tags_views_handlers() {
  return array(
    'handlers' => array(
      'views_handler_field_node_community_tag_form' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

function community_tags_views_data_alter(&$data) {
  $data['node']['community_tag_form'] = array(
    'title' => t('Community Tag form'),
    'help' => t('The form for community tag'),
    'field' => array(
      'handler' => 'views_handler_field_node_community_tag_form',
    ),
  );
}
