/*
 * Copyright (c) 2007, 2018, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2.0,
 * as published by the Free Software Foundation.
 *
 * This program is designed to work with certain software (including
 * but not limited to OpenSSL) that is licensed under separate terms, as
 * designated in a particular file or component or in included license
 * documentation.  The authors of MySQL hereby grant you an additional
 * permission to link the program and your derivative works with the
 * separately licensed software that they have either included with
 * the program or referenced in the documentation.
 * This program is distributed in the hope that it will be useful,  but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
 * the GNU General Public License, version 2.0, for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA 
 */

#include "editor_view.h"
#include "base/string_utilities.h"

using namespace grt;
using namespace bec;
using namespace base;

//--------------------------------------------------------------------------------------------------

ViewEditorBE::ViewEditorBE(const db_ViewRef &view) : DBObjectEditorBE(view) {
  MySQLEditor::Ref sql_editor = get_sql_editor();
  if (sql_editor)
    sql_editor->restrict_content_to(MySQLEditor::ContentTypeView);
}

//--------------------------------------------------------------------------------------------------

std::string ViewEditorBE::get_sql() {
  std::string sql = DBObjectEditorBE::get_sql();
  if (sql.empty())
    sql = "CREATE VIEW `" + get_name() + "` AS\n";

  return sql;
}

//--------------------------------------------------------------------------------------------------

std::string ViewEditorBE::get_title() {
  return get_name() + " - View";
}

//--------------------------------------------------------------------------------------------------
