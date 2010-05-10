<?php

class views_handler_field_node_community_tag_form extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['nid'] = array(
      'field' => 'nid',
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $nodeid = $values->{$this->aliases['nid']};

    return community_tags_node_view($nodeid, TRUE);
  }
}
