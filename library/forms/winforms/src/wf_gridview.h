/*
 * Copyright (c) 2014, 2018, Oracle and/or its affiliates. All rights reserved.
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

#pragma once

using namespace System;
using namespace System::Windows::Forms;

namespace MySQL {
  namespace Forms {
  public
    delegate MySQL::Base::IRecordsetView ^
      CreateGridViewDelegate(IntPtr /* to a std::shared_ptr<Recordset> ptr */ rset);

    ref class ColumnCallbackWrapper;

  public
    class GridViewWrapper : public NativeWrapper {
      static gcroot<CreateGridViewDelegate ^> factory;
      gcroot<ColumnCallbackWrapper ^> column_callback_delegate;

    public:
      static mforms::GridView* create(std::shared_ptr<class ::Recordset> rset);
      static void init(CreateGridViewDelegate ^ creator);

      GridViewWrapper(mforms::GridView* backend);
      virtual ~GridViewWrapper();
    };

  public
    ref class GridViewHelper {
    public:
      static void init(CreateGridViewDelegate ^ creator) {
        GridViewWrapper::init(creator);
      }
    };
  }
}
