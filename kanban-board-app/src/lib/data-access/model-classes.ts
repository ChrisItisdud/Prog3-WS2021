export class Item {
  title: string;
  position: number;
  timestamp: string;
  column_id: number;
}

export class Column {
  name: string;
  position: number;
  items: Item[];
}

export class Board {
  name: string;
  columns: Column[];
}
