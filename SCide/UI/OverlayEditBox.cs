﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ASM.Utilit;

namespace ASM.UI
{
    public partial class OverlayEditBox : Form
    {
        private object obj;
        private PropertyDescriptor prop;

        public OverlayEditBox(Control control, string propName)
            : this(control, propName, control.PointToScreen(new Point(0, 0)))
        {
            InputHook.MouseDown += OnGlobalMouseDown;
        }

        public OverlayEditBox(object Obj, string propName, Point position)
        {
            InitializeComponent();
            obj = Obj;
            prop = TypeDescriptor.GetProperties(obj).Find(propName, true);
            Location = position;
        }

        private void OverlayEditBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                Close();
                Control c = obj as Control;
                if (c != null)
                    c.Invoke((Action)(() => setValue()));
                else
                    setValue();
            }
            else if (e.KeyCode == Keys.Escape)
                Close();
        }

        private void setValue()
        {
            prop.SetValue(obj, prop.Converter.ConvertTo(editor.Text, prop.PropertyType));
        }

        private void OnGlobalMouseDown(object sender, MouseEventArgs e)
        {
            if (!Bounds.Contains(e.Location))
                Close();
        }

        private void OverlayEditBox_Leave(object sender, EventArgs e)
        {
            Close();
        }

        protected override void OnClosing(CancelEventArgs e)
        {
            InputHook.MouseDown -= OnGlobalMouseDown;
            base.OnClosing(e);
        }
    }
}