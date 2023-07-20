object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Proyecto Archivos Carlos Diego M.P.'
  ClientHeight = 302
  ClientWidth = 458
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 32
    Top = 20
    Width = 209
    Height = 33
    Caption = 'ABM Alumnos.dat'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 120
    Top = 112
    Width = 37
    Height = 13
    Caption = 'Codigo:'
  end
  object Label3: TLabel
    Left = 116
    Top = 144
    Width = 41
    Height = 13
    Caption = 'Nombre:'
  end
  object Label4: TLabel
    Left = 110
    Top = 176
    Width = 47
    Height = 13
    Caption = 'Direccion:'
  end
  object Label5: TLabel
    Left = 54
    Top = 208
    Width = 103
    Height = 13
    Caption = 'Fecha de Nacimiento:'
  end
  object Edit1: TEdit
    Left = 184
    Top = 109
    Width = 121
    Height = 21
    TabOrder = 0
    OnExit = Edit1Exit
  end
  object Edit2: TEdit
    Left = 184
    Top = 141
    Width = 241
    Height = 21
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 184
    Top = 173
    Width = 241
    Height = 21
    TabOrder = 2
  end
  object Button1: TButton
    Left = 64
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Guardar'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 184
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Eliminar'
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 304
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Limpiar'
    TabOrder = 5
    OnClick = Button3Click
  end
  object MaskEdit1: TMaskEdit
    Left = 185
    Top = 205
    Width = 56
    Height = 21
    EditMask = '!99/99/00;1;_'
    MaxLength = 8
    TabOrder = 6
    Text = '  /  /  '
  end
  object Button4: TButton
    Left = 282
    Top = 8
    Width = 160
    Height = 25
    Caption = 'NavegadorIdx'
    TabOrder = 7
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 282
    Top = 39
    Width = 80
    Height = 25
    Caption = '<<'
    TabOrder = 8
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 362
    Top = 39
    Width = 80
    Height = 25
    Caption = '>>'
    TabOrder = 9
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 282
    Top = 70
    Width = 160
    Height = 25
    Caption = 'Fin'
    TabOrder = 10
    OnClick = Button7Click
  end
  object MainMenu1: TMainMenu
    Left = 24
    Top = 72
    object Indices1: TMenuItem
      Caption = 'Indices'
      object Indices2: TMenuItem
        Caption = 'Por Codigo'
        OnClick = Indices2Click
      end
      object PorNombre1: TMenuItem
        Caption = 'Por Nombre'
        OnClick = PorNombre1Click
      end
    end
    object Ordenar1: TMenuItem
      Caption = 'Ordenar'
      object Ordenar2: TMenuItem
        Caption = 'Por Codigo'
        OnClick = Ordenar2Click
      end
      object PorNombre2: TMenuItem
        Caption = 'Por Nombre '
      end
    end
  end
end
