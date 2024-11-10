CREATE TABLE tenants (
    tenant_id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    phone TEXT NOT NULL,
    email TEXT NOT NULL,
    apartment_number INTEGER NOT NULL,
    check_in_date TEXT NOT NULL,
    check_out_date TEXT
);

CREATE TABLE maintenance_requests (
    request_id INTEGER PRIMARY KEY AUTOINCREMENT,
    apartment_number INTEGER NOT NULL,
    area TEXT NOT NULL,
    description TEXT NOT NULL,
    date_time TEXT NOT NULL,
    photo TEXT,
    status TEXT DEFAULT 'pending'
);


